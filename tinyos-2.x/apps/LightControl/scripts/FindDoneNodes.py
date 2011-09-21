#! /usr/bin/python

import sys
import gc
import getopt
from EventFields import *

BCAST_ADDR = '65535'

class AppState:
    def __init__(self, verbose=False):
        self.verbose = verbose
        self.acquire_times = []
        self.grant_times = []
        self.release_times = []
        self.sync_times = []
        self.priorities = []
        self.entry_handlers = { 'ACQUIRE':self.AcquireEntry,
                                'GRANTED':self.GrantedEntry,
                                'RELEASE':self.ReleaseEntry,
                                'SYNCED':self.SyncedEntry }

    def AcquireEntry(self, logentry):
        acquire_time = logentry['time']
        self.acquire_times.append(logentry['time'])
        pr = int(logentry['rest'][1])
        self.priorities.append(pr)
        if self.verbose:
            print '[%d] Requested lock with pr %d' % (acquire_time, pr)

    def GrantedEntry(self, logentry):
        self.grant_times.append(logentry['time'])

    def ReleaseEntry(self, logentry):
        self.release_times.append(logentry['time'])

    def SyncedEntry(self, logentry):
        self.sync_times.append(logentry['time'])

    def DefaultHandler(self, logentry):
        pass

    def LogHandler(self, logentry):
        subtype = logentry['rest'][0]
        self.entry_handlers.get(subtype, self.DefaultHandler)(logentry)

class Node:
    def __init__(self, nodeid, verbose=False):
        # Object for parsing Lock events at the app level
        self.appstate = AppState(verbose)
        self.id = nodeid
        # dict of estimates for each actuator
        # { 0: [e0, e1, ..], 
        #   1: [e0, e1, ..], ... }
        self.estimates = {}
        # list of packets Tx by this node
        # Each pkt is a dict:
        # { 'time': simulation time, 
        #   'nodetime': local ndoe time, 
        #   'seq': sequence number }
        self.tx = []
        # list of packets Rx by this node
        # Each pkt is a dict:
        # { 'time': simulation time, 
        #   'nodetime': local ndoe time, 
        #   'seq': sequence number,
        #   'src': source node id }
        self.rx = []
        self.log_entry_handlers = { "APP":self.appstate.LogHandler,
                                    "ESTIMATE":self.EstimateHandler,
                                    "TX":self.TxHandler,
                                    "RX":self.RxHandler,
                                    "##":self.CommentHandler }
        self.verbose = verbose
        # Extra debugging variables
        self.done = 0
        self.doneiter = []
        self.restarts = 0
        self.restartiter = []

    def _defaultLogHandler(self, logentry):
        pass

    def CommentHandler(self, logentry):
        if 'StoppingNoEvents' in logentry['rest']:
            self.done += 1
            self.doneiter += [ int(logentry['rest'][0]) ]
        if 'StartIter' in logentry['rest']:
            self.restarts += 1
            self.restartiter += [ int(logentry['rest'][0]) ]
        pass

    def EstimateHandler(self, logentry):
        # Store this estimate as a dict item:
        # e = { 'value': .., 'time': .., 'iteration': .. }
        # in a list corresponding to the actuator id
        e = {}
        act_id = int(logentry['rest'][0])
        iteration = int(logentry['rest'][1])
        value = float(logentry['rest'][2])
        e['iteration'] = iteration
        e['time'] = logentry['time']
        e['value'] = value
        if self.verbose:
            print 'Node[%d]: Adding %s for actuator %d.'%(self.id,e,act_id)
        if act_id not in self.estimates:
            self.estimates[act_id] = []
        self.estimates[act_id].append(e)

    def TxHandler(self, logentry):
        e = {}
        e['time'] = logentry['time']
        e['nodetime'] = int(logentry['rest'][0])
        e['seq'] = int(logentry['rest'][1])
        self.tx.append(e)

    def RxHandler(self, logentry):
        e = {}
        e['time'] = logentry['time']
        e['nodetime'] = int(logentry['rest'][0])
        e['seq'] = int(logentry['rest'][1])
        e['src'] = int(logentry['rest'][3])
        self.rx.append(e)

    def UpdateState(self, logentry):
        # logentry: dictionary of a single log entry
        self.log_entry_handlers.get(logentry['type'],
                self._defaultLogHandler)(logentry)

class Parser:
    def __init__(self, verbose=False, simulation=True):
        self.verbose = verbose
        self.simulation = simulation
        self.nodes = {}

    def Parse(self, filename):
        self.nodes = {}
        gc.collect()
        ev = EventFields(False, self.simulation)
        #ev = EventFields(self.verbose, self.simulation)
        f = open(filename, 'r')
        if self.verbose:
            print 'Opened file: ', filename
        for line in f:
            logentry = ev.Get(line)
            nodeid = logentry['node']
            if nodeid not in self.nodes:
                self.nodes[nodeid] = Node(nodeid, self.verbose)
            self.nodes[nodeid].UpdateState(logentry)
        f.close()
        return self.nodes


if (__name__ == '__main__'):
    try:
        opts, args = getopt.getopt(sys.argv[1:], "vef:", ["verbose", "errors", "file"])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    list_errors = False
    filename = 'try.txt'
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-e", "--errors"):
            list_errors = True
        elif o in ("-f", "--file"):
            filename = a
    p = Parser(verbose)
    nodes = p.Parse(filename)
    for (n, objn) in nodes.iteritems():
        if objn.done == 0:
            print 'Node %d : NOT COMPLETE'%(n)
        elif objn.done > 1:
            print 'Node %d : stopped more than once'%(n)
            print 'Iteration numbers - ', objn.doneiter
        else:
            print 'Node %d : stopped at %d'%(n,objn.doneiter[0])
        if objn.restarts > 0:
            print 'Node %d : restarted after stopping'%(n)
            print 'Iteration numbers - ', objn.restartiter
        print '-----------------------------------'

