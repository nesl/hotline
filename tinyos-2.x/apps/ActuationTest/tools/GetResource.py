#! /usr/bin/env python

######################################################################
# This module parses a single log file and returns the statistics as
# a dictionary of the following iterms for each node.
# 'rt': [ ... ] list of response times for each iteration
# 'acquiretimes': [ ... ] list of times at which node requested lock
# 'releasetimes': [ ... ] list of times at which node released lock
# 'nbr': [ tx, rx, zonerx ] 
#   tx, rx - [ .. ] list of times at which zone beacons tx'ed and rx'ed
#   zonerx - [ .. ] list of times at which new zone info received from nbrs
# 'id': node id
# 'tries': total number of times the node had to retry lock requests
# 'reliability': ( total, success ) number of total and successful iterations
#       as detected by the node at runtime
# 'conflicts': ( num, [..] ) number of lock violations detected by the 
#       parser from log file, and list of conflicting neighbors
# 'violations': number of lock violations detected by the node at runtime
# 'deadlock': [NOT APPLICABLE AT MORE] number of deadlocks
# 'requests': total number of iterations (lock requests)
# 'mpcs': [ ... ] list of number of messages exchanged per iteration
######################################################################

import sys
import getopt
import math

class EventFields:
    def __init__(self, verbose=False, simulation=True):
        self.verbose = verbose
        # Default: Extract fields from a TOSSIM simulation log
        # DEBUG (<id>): .....
        # simulation=False: Extract from a mote log
        # <Timestamp(ms)> DEBUG (<id>): ....
        self.simulation = simulation
        self.log_dict = {}

    def ExtractId(self, s):
        # Extract id=n from string '(n):'
        fields = s.split('(')
        fields = fields[1].split(')');
        return int(fields[0])

    def ExtractEvent(self, s):
        # Extract events from string 's_s_...'
        fields = s.split('_')
        return fields

    def ConvertTime(self, s):
        # Convert time to seconds from 'hh:mm:ss.ms'
        fields = s.split(':')
        hh = int(fields[0])
        mm = int(fields[1])
        ss = float(fields[2])
        return ( (hh*60*60)+(mm*60)+ss )

    def _getSimFields(self, line):
        # line: read from a log file
        self.log_dict = {}
        rawfields = line.split()
        self.log_dict['node'] = self.ExtractId(rawfields[1])
        logfields = self.ExtractEvent(rawfields[2])
        self.log_dict['type'] = logfields[0]
        self.log_dict['time'] = self.ConvertTime(logfields[1])
        self.log_dict['rest'] = logfields[2:]
        if self.verbose:
            print self.log_dict
        return self.log_dict

    def _getMoteFields(self, line):
        # line: read from a log file
        # <Timestamp(ms)> DEBUG (<id>): ....
        self.log_dict = {}
        rawfields = line.split()
        self.log_dict['time'] = float(rawfields[0])/1000.0
        self.log_dict['node'] = self.ExtractId(rawfields[2])
        logfields = self.ExtractEvent(rawfields[3])
        self.log_dict['type'] = logfields[0]
        self.log_dict['motetime'] = int(logfields[1])
        self.log_dict['rest'] = logfields[2:]
        if self.verbose:
            print self.log_dict
        return self.log_dict

    def Get(self, line):
        if self.simulation:
            return self._getSimFields(line)
        else:
            return self._getMoteFields(line)

DEFAULT = 0
START_COUNT = 1
STOP_COUNT = 2

BCAST_ADDR = '65535'

class AppState:
    def __init__(self, verbose=False):
        self.active_nodes = []
        self.timeline = []
        self.entry_handlers = { 'ACQUIRE':self.AcquireEntry,
                                'GRANTED':self.GrantedEntry,
                                'TRYEXPIRED':self.TryEntry,
                                'HOLDEXPIRED':self.HoldEntry,
                                'VIOLATION':self.ConflictEntry,
                                'RELEASE':self.ReleaseEntry }
        self.verbose = verbose

    def GrantedEntry(self, logentry):
        if self.verbose:
            print 'Add: ', logentry['node']
        self.active_nodes.append( logentry['node'] )
        self.timeline.append( list(self.active_nodes) )

    def ReleaseEntry(self, logentry):
        if self.verbose:
            print 'Remove: ', logentry['node']
        self.active_nodes.remove( logentry['node'] )
        self.timeline.append( list(self.active_nodes) )

    def AcquireEntry(self, logentry):
        pass

    def TryEntry(self, logentry):
        pass

    def ConflictEntry(self, logentry):
        pass

    def HoldEntry(self, logentry):
        pass

    def DefaultHandler(self, logentry):
        pass

    def LogHandler(self, logentry):
        subtype = logentry['rest'][0]
        self.entry_handlers.get(subtype, self.DefaultHandler)(logentry)

    def GetTimeline(self):
        return self.timeline

class LogFileParser:
    def __init__(self, verbose=False, simulation=True):
        self.appstate = AppState(verbose)
        self.log_entry_handlers = { "APP":self.appstate.LogHandler }
        self.verbose = verbose
        self.simulation = simulation
        self.nodes = {}

    def _defaultHandler(self, logentry):
        pass

    def UpdateState(self, logentry):
        # logentry: dictionary of a single log entry
        self.log_entry_handlers.get(logentry['type'],
                self._defaultHandler)(logentry)

    def ParseFile(self, filename):
        self.nodes = {}
        ev = EventFields(self.verbose, self.simulation)
        f = open(filename, 'r')
        if self.verbose:
            print 'Opened file: ', filename
        for line in f:
            logentry = ev.Get(line)
            self.UpdateState(logentry)

    def PrintFile(self, outfilename):
        outfile = open(outfilename, 'w')
        timeline = self.appstate.GetTimeline()
        print 'Writing timeline to file: ', outfilename
        i = 0
        for r in timeline:
            writestr = str(i) + '\t' + str(len(r))
            i = i + 1
            if self.verbose:
                print writestr
            outfile.write(writestr+'\n')
        outfile.close()

######################################################################
# Testing + stand-alone use to parse files from a list given manually 
######################################################################

if (__name__ == '__main__'):
    try:
        longopts = ["verbose", "motes", "log="]
        opts, args = getopt.getopt(sys.argv[1:], "vml:", longopts)
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    simulation = True
    logfile = 'out.txt'
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-l", "--log"):
            logfile = a
        elif o in ("-m", "--motes"):
            simulation = False
    lf = LogFileParser(verbose, simulation)
    lf.ParseFile(logfile)
    lf.PrintFile(logfile+'.out')
