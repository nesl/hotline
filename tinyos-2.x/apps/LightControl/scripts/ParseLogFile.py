#! /usr/bin/python

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
        # Record iteration number and value of each event.
        # Save it as a dictionary keyed on iteration number:
        # { iteration: val1, .. }
        self.events = {}
        self.entry_handlers = { 'ACQUIRE':self.AcquireEntry,
                                'GRANTED':self.GrantedEntry,
                                'RELEASE':self.ReleaseEntry,
                                'USEREVENT':self.EventEntry,
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

    def EventEntry(self, logentry):
        iteration = int(logentry['rest'][1])
        value = int(logentry['rest'][2])
        self.events[iteration] = value

    def DefaultHandler(self, logentry):
        pass

    def LogHandler(self, logentry):
        subtype = logentry['rest'][0]
        self.entry_handlers.get(subtype, self.DefaultHandler)(logentry)

class Token:
    def __init__(self, verbose=False):
        self.verbose = verbose
        self.tx_msg = {}
        self.rx_msg = {}
        self.link_pkts = 0
        self.entry_handlers = { 'TOKEN':self.CountMessages,
                                'RING':self.LinkPackets }

    def CountMessages(self, logentry):
        token = int(logentry['rest'][0])
        if 'TX' in logentry['rest']:
            seq = int(logentry['rest'][3])
            if token not in self.tx_msg:
                self.tx_msg[token] = {}
            if seq not in self.tx_msg[token]:
                self.tx_msg[token][seq] = 0
            self.tx_msg[token][seq] += 1
        elif 'RX' in logentry['rest']:
            seq = int(logentry['rest'][2])
            if token not in self.rx_msg:
                self.rx_msg[token] = {}
            if seq not in self.rx_msg[token]:
                self.rx_msg[token][seq] = 0
            self.rx_msg[token][seq] += 1

    def LinkPackets(self, logentry):
        if 'ACK' not in logentry['rest']:
            self.link_pkts += 1

    def GetLinkPackets(self):
        return self.link_pkts

    def GetMessages(self):
        msgcount = sum([ max(tmsg.values()) if len(tmsg)>0 else 0 for tmsg in
            self.tx_msg.itervalues() ])
        msgcount += sum([ max(rmsg.values()) if len(rmsg)>0 else 0 for rmsg in
            self.rx_msg.itervalues() ])
        return msgcount

    def DefaultHandler(self, logentry):
        pass

    def LogHandler(self, logentry):
        subtype = logentry['type']
        self.entry_handlers.get(subtype, self.DefaultHandler)(logentry)

class Node:
    def __init__(self, parserobj, nodeid, verbose=False):
        # Object for parsing Lock events at the app level
        self.appstate = AppState(verbose)
        self.tokenmsg = Token(verbose)
        self.id = nodeid
        self.parserobj = parserobj
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
        # This is used for all EXP except CYCLIC.
        # Total number of messages exchanged by this node.
        # It does not reflect any impact of network stack and characteristics.
        self.msg_count = 0
        # This keeps track of all SYNC messages exchanged by this node.
        # It is always <= self.msg_count as msg_count counts it too.
        # Useful in Multi-hop scenarios to calculate total messages exchanged
        # by this node using its 'ntable'.
        # It does not reflect any impact of network stack and characteristics.
        self.sync_msg_count = 0
        # This is used for all EXP except CYCLIC
        # Record cumulative message count at the end of each iteration.
        # Its a dictionary: { 'iter number' : msg count, ... }
        self.cum_msgs = {}
        self.cum_sync_msgs = {}
        # This is only used in CYCLIC implementation.
        # Record cumulative token message count at the end of each iteration.
        # Its a dictionary: { 'iter number' : msg count, ... }
        self.cum_token_msgs = {}
        # This is only used in CYCLIC implementation.
        # Record cumulative token link pkt count at the end of each iteration.
        # Its a dictionary: { 'iter number' : msg count, ... }
        self.cum_token_pkts = {}
        # Record all the sensor values measured by this node.
        self.sensorvalues = {}
        # List of neighbors of this node. 
        self.ntable = []
        # Distionary of logical times at which this node was scheduled
        # { iteration: time, iteration1:time1, ... }
        self.schedule = {}
        self.log_entry_handlers = { "APP":self.appstate.LogHandler,
                                    "ESTIMATE":self.EstimateHandler,
                                    "NEIGHBOR":self.NeighborHandler,
                                    "SENSOR":self.SensorHandler,
                                    "TX":self.TxHandler,
                                    "RX":self.RxHandler,
                                    "TOKEN":self.tokenmsg.LogHandler,
                                    "RING":self.tokenmsg.LogHandler,
                                    "##":self.CommentHandler }
        self.verbose = verbose

    def _defaultLogHandler(self, logentry):
        pass

    def CommentHandler(self, logentry):
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
        if iteration not in self.cum_msgs:
            self.cum_msgs[iteration] = self.msg_count
            self.cum_sync_msgs[iteration] = self.sync_msg_count
        # Record token counts at all the nodes as in the CYCLIC implementation
        # only node 0 has ESTIMATE logs
        self.parserobj.updateTokenCounts(iteration)
        self.schedule[iteration] = self.parserobj.getScheduleTime(self.id,
            iteration)

    def updateTokenCount(self, iteration):
        if iteration not in self.cum_token_msgs:
            self.cum_token_msgs[iteration] = self.tokenmsg.GetMessages()
        if iteration not in self.cum_token_pkts:
            self.cum_token_pkts[iteration] = self.tokenmsg.GetLinkPackets()

    def NeighborHandler(self, logentry):
        # logentry['rest'] = [ 'TABLE', 'n1', 'n2' ]
        self.ntable = [ int(v) for v in logentry['rest'][1:] ]

    def TxHandler(self, logentry):
        e = {}
        e['time'] = logentry['time']
        e['nodetime'] = int(logentry['rest'][0])
        e['seq'] = int(logentry['rest'][1])
        e['sync'] = False
        if 'TxSync' in logentry['rest']:
            e['sync'] = True
            self.sync_msg_count += 1
        self.tx.append(e)
        self.msg_count += 1

    def RxHandler(self, logentry):
        e = {}
        e['time'] = logentry['time']
        e['nodetime'] = int(logentry['rest'][0])
        e['seq'] = int(logentry['rest'][1])
        e['src'] = int(logentry['rest'][3])
        e['sync'] = False
        if 'RxSync' in logentry['rest']:
            e['sync'] = True
            self.sync_msg_count += 1
        self.rx.append(e)
        self.msg_count += 1

    def SensorHandler(self, logentry):
        self.sensorvalues[int(logentry['time'])] = int(logentry['rest'][0])

    def UpdateState(self, logentry):
        # logentry: dictionary of a single log entry
        self.log_entry_handlers.get(logentry['type'],
                self._defaultLogHandler)(logentry)

class Parser:
    def __init__(self, verbose=False, simulation=True):
        self.verbose = verbose
        self.simulation = simulation
        self.nodes = {}
        self.currentTime = -1
        # ID of last scheduled node and its iteration number
        self.last_scheduled = (-1, -1)

    def getScheduleTime(self, nodeid, iteration):
        if nodeid == self.last_scheduled[0]:
            if iteration == self.last_scheduled[1]:
                return self.currentTime
        # Save the node identfier and iteration of last scheduled node
        self.last_scheduled = (nodeid, iteration)
        self.currentTime += 1
        return self.currentTime

    def updateTokenCounts(self, iteration):
        for objn in self.nodes.itervalues():
            objn.updateTokenCount(iteration)

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
                self.nodes[nodeid] = Node(self, nodeid, self.verbose)
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
        print '[%d] - %d'%(n,len(objn.appstate.sync_times))
        print 'PR - %d'%(objn.appstate.priorities[0])
        print '-----------------------------------'

