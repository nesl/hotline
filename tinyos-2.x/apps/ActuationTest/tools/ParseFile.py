#! /usr/bin/env python

######################################################################
# This module parses a single log file and returns the statistics as
# a dictionary of the following iterms for each node.
# 'rt': [ ... ] list of response times for each iteration
# 'acquiretimes': [ ... ] list of times at which node requested lock
# 'granttimes'  : [ ... ] list of times at which node acquired lock
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

import sys, gc
import getopt
import math
from EventFields import *

DEFAULT = 0
START_COUNT = 1
STOP_COUNT = 2
START_SYNC_COUNT = 3
STOP_SYNC_COUNT = 4

BCAST_ADDR = '65535'

class SVRState:
    def __init__(self, verbose=False):
        self.tx_count = 0
        self.rx_pkt = {}
        self.stored_action = STOP_SYNC_COUNT
        self.verbose = verbose

    def LogHandler(self, logentry, action):
        # It is a Tx/Rx message. Increment count if reqd.
        if 'TX' in logentry['rest']:
            self.tx_count = self.tx_count + 1
        elif 'RX' in logentry['rest']:
            seq = int(logentry['rest'][2])
            pmask = int(logentry['rest'][3])
            mmask = int(logentry['rest'][5])
            if seq not in self.rx_pkt:
                # Its a new sequence number. Initialize the new entry.
                self.rx_pkt[seq] = {}
            if pmask in self.rx_pkt[seq]:
                # Seen this pkt before too. Increment its count.
                self.rx_pkt[seq][pmask] += 1
            else:
                # Its a new pkt. Add a new entry for this pkt mask.
                self.rx_pkt[seq][pmask] = 1
        return action

#    def LogHandler(self, logentry, action):
#        # It is a Tx/Rx message. Increment count if reqd.
#        if action == START_SYNC_COUNT:
#            self.tx_count = 0
#            self.rx_pkt = {}
#            self.stored_action = action
#        if action == STOP_SYNC_COUNT:
#            self.stored_action = action
#        if self.stored_action == START_SYNC_COUNT:
#            if 'TX' in logentry['rest']:
#                self.tx_count = self.tx_count + 1
#            elif 'RX' in logentry['rest']:
#                seq = int(logentry['rest'][2])
#                pmask = int(logentry['rest'][3])
#                mmask = int(logentry['rest'][5])
#                if seq not in self.rx_pkt:
#                    # Its a new sequence number. Initialize the new entry.
#                    self.rx_pkt[seq] = {}
#                if pmask in self.rx_pkt[seq]:
#                    # Seen this pkt before too. Increment its count.
#                    self.rx_pkt[seq][pmask] += 1
#                else:
#                    # Its a new pkt. Add a new entry for this pkt mask.
#                    self.rx_pkt[seq][pmask] = 1
#        # Do not interfere with LockState
#        if action == START_COUNT:
#            return action
#        if action == STOP_COUNT:
#            return action
#        return DEFAULT

    def GetTxRxCount(self):
        rx_count = sum([ max([n for n in seqpkt.itervalues()]) if seqpkt != {} else 0 for
            seqpkt in self.rx_pkt.itervalues() ])
        return self.tx_count + rx_count

class SyncState:
    def __init__(self, verbose=False):
        self.tx_sync = {}
        self.rx_sync = {}
        self.verbose = verbose

    def LogHandler(self, logentry, action):
        if 'TxSync' in logentry['rest']:
            iternum = int(logentry['rest'][1])
            self.tx_sync[iternum] = logentry['time'] 
        elif 'RxSync' in logentry['rest']:
            iternum = int(logentry['rest'][1])
            naddr = int(logentry['rest'][3])
            if iternum not in self.rx_sync:
                # Sync for a new iteration number
                self.rx_sync[iternum] = {}
            self.rx_sync[iternum][naddr] = logentry['time'] 
        return action

    def GetSyncs(self):
        return (self.tx_sync, self.rx_sync)


class LockState:
    def __init__(self, verbose=False):
        self.ntable = []
        self.msg_count = 0
        self.tx_count = 0
        self.rx_count = 0
        self.rx_broadcast = []
        self.stored_action = STOP_COUNT
        self.total_trans = 0
        self.success_trans = 0
        # Number of retry request attempts
        self.tries = 0
        self.verbose = verbose

    def LogHandler(self, logentry, action):
        if action == START_COUNT:
            self.msg_count = 0
            self.stored_action = action
        if action == STOP_COUNT:
            self.stored_action = action
        if 'STATE' in logentry['rest']:
            # It is just a state logging message
            if 'TRYEXPIRED' in logentry['rest']:
                self.TryEntry()
            return DEFAULT
        if 'VIOLATIONS' in logentry['rest']:
            self.ExtractReliability(logentry)
            return DEFAULT
        # It is a Tx/Rx message. Increment count if reqd.
        if self.stored_action == START_COUNT:
            self.msg_count = self.msg_count + 1
        if 'TX' in logentry['rest']:
            self.tx_count = self.tx_count + 1
        if 'RX' in logentry['rest']:
            if BCAST_ADDR in logentry['rest']:
                # Rcvd broadcast
                neighbor_id = int(logentry['rest'][3])
                self.rx_broadcast.append(neighbor_id)
            else:
                # Rcvd directed message
                self.rx_count = self.rx_count + 1
        # Do not interfere with SVRState
        if action == START_SYNC_COUNT:
            return action
        if action == STOP_SYNC_COUNT:
            return action
        return DEFAULT

    def UpdateNeighbors(self, ntable):
        self.ntable = ntable

    def GetMsgCount(self):
        return self.msg_count

    def GetTxRxCount(self):
        return (self.tx_count, self.rx_count, self.rx_broadcast)

    def GetReliability(self):
        return (self.total_trans, self.success_trans)

    def TryEntry(self):
        self.tries += 1

    def GetRetries(self):
        return self.tries

    def ExtractReliability(self, logentry):
        self.total_trans = int(logentry['rest'][1])
        self.success_trans = int(logentry['rest'][2])
        pass

class AppState:
    def __init__(self, verbose=False):
        self.ntable = []
        # Keep note of response time
        self.acquire_time = None
        self.grant_time = None
        self.release_time = None
        self.num_requests = 0
        self.rt_per_request = []
        self.grant_times = []
        self.acquire_times = []
        self.release_times = []
        self.sync_times = []
        self.detected_conflicts = 0
        # tries is now here only for backwards compatibility ;)
        self.tries = 0
        self.last_known_action = DEFAULT
        self.entry_handlers = { 'ACQUIRE':self.AcquireEntry,
                                'GRANTED':self.GrantedEntry,
                                'SYNCED':self.SyncedEntry,
                                'RELEASE':self.ReleaseEntry, }
        self.stats_dict = {}
        self.verbose = verbose

    def AcquireEntry(self, logentry):
        self.num_requests += 1
        self.acquire_time = logentry['time']
        self.acquire_times.append(logentry['time'])
        trytime = int(logentry['rest'][1])
        metric = int(logentry['rest'][2])
        if self.verbose:
            print self.acquire_time, trytime, metric
        self.last_known_action = START_COUNT
        return START_COUNT

    def GrantedEntry(self, logentry):
        self.grant_time = logentry['time']
        self.grant_times.append(logentry['time'])
        self.rt_per_request.append(self.grant_time - self.acquire_time)
        self.last_known_action = STOP_COUNT
        return STOP_COUNT

    def ReleaseEntry(self, logentry):
        self.release_time = logentry['time']
        self.release_times.append(logentry['time'])
        #self.last_known_action = START_SYNC_COUNT
        self.last_known_action = DEFAULT
        return self.last_known_action

    def SyncedEntry(self, logentry):
        self.sync_times.append(logentry['time'])
        #self.last_known_action = STOP_SYNC_COUNT
        self.last_known_action = DEFAULT
        return self.last_known_action

    def DefaultHandler(self, logentry):
        return self.last_known_action

    def LogHandler(self, logentry, action):
        subtype = logentry['rest'][0]
        return self.entry_handlers.get(subtype, self.DefaultHandler)(logentry)

    def UpdateNeighbors(self, ntable):
        self.ntable = ntable

    def Overlaps(self, neighbor, selfiter, nbriter):
        self_rtime = self.release_times[selfiter]
        nbr_rtime = neighbor.release_times[nbriter]
        self_gtime = self.grant_times[selfiter]
        nbr_gtime = neighbor.grant_times[nbriter]
        if self_rtime <= nbr_gtime:
            return False
        if nbr_rtime <= self_gtime:
            return False
        return True

    def GetStats(self):
        self.stats_dict['rt'] = self.rt_per_request
        self.stats_dict['deadlock'] = len(self.acquire_times)-len(self.grant_times)
        self.stats_dict['requests'] = self.num_requests
        self.stats_dict['releasetimes'] = self.release_times
        self.stats_dict['acquiretimes'] = self.acquire_times
        self.stats_dict['granttimes'] = self.grant_times
        self.stats_dict['synctimes'] = self.sync_times
        return self.stats_dict

class Node:
    def __init__(self, nodeid, verbose=False):
        self.id = nodeid
        self.lockstate = LockState(verbose)
        self.svrstate = SVRState(verbose)
        self.syncstate = SyncState(verbose)
        self.appstate = AppState(verbose)
        self.ntable = []
        self.msg_counts = []
        #self.sync_counts = []
        self.log_entry_handlers = { "APP":self.appstate.LogHandler,
                                    "LOCK":self.lockstate.LogHandler,
                                    "RX":self.syncstate.LogHandler,
                                    "TX":self.syncstate.LogHandler,
                                    "SVR":self.svrstate.LogHandler }
        self.nbr_entry_handlers = { "TABLE":self.NeighborTableHandler,
                                    "BEACON":self.NeighborBeaconHandler }
        self.action = DEFAULT
        self.verbose = verbose
        self.nbr_msg_tx = []
        self.nbr_msg_rx = []
        self.nbr_msg_zone_rx = []

    def _defaultNbr(self, logentry, action):
        return action

    def NeighborHandler(self, logentry, action):
        # logentry['rest'] = [ 'TABLE', 'n1', 'n2' ]
        self.nbr_entry_handlers.get(logentry['rest'][0],
                self._defaultNbr)(logentry, action)
        return action

    def NeighborTableHandler(self, logentry, action):
        # logentry['rest'] = [ 'TABLE', 'n1', 'n2' ]
        self.ntable = [ int(v) for v in logentry['rest'][1:] ]
        self.nbr_msg_zone_rx.append(logentry['time'])
        self.lockstate.UpdateNeighbors(self.ntable)
        self.appstate.UpdateNeighbors(self.ntable)

    def NeighborBeaconHandler(self, logentry, action):
        # logentry['rest'] = [ 'BEACON', 'TX' ]
        # logentry['rest'] = [ 'BEACON', 'RX' ]
        if 'TX' in logentry['rest']:
            self.nbr_msg_tx.append(logentry['time'])
        if 'RX' in logentry['rest']:
            self.nbr_msg_rx.append(logentry['time'])

    def UpdateState(self, logentry):
        # logentry: dictionary of a single log entry
        self.action = self.log_entry_handlers.get(logentry['type'],
                self.NeighborHandler)(logentry, self.action)
        if self.action == STOP_COUNT:
            self.msg_counts.append(self.lockstate.GetMsgCount())
        #if self.action == STOP_SYNC_COUNT:
        #    self.sync_counts.append(self.svrstate.GetTxRxCount())

    def Overlaps(self, neighbor, it1, it2):
        return self.appstate.Overlaps(neighbor.appstate, it1, it2)

    def GetTxRxCount(self):
        return self.lockstate.GetTxRxCount()

    def GetSyncTimes(self):
        return self.syncstate.GetSyncs()

    def GetStats(self):
        res_dict = self.appstate.GetStats()
        if self.msg_counts == []:
            self.msg_counts.append(self.lockstate.GetMsgCount())
        res_dict['mpcs'] = self.msg_counts
        #res_dict['synccost'] = self.sync_counts
        res_dict['synccost'] = self.svrstate.GetTxRxCount()/len(self.syncstate.tx_sync)
        res_dict['tries'] = self.lockstate.GetRetries()
        res_dict['reliability'] = self.lockstate.GetReliability()
        res_dict['nbr'] = [ self.nbr_msg_tx, self.nbr_msg_rx,
                self.nbr_msg_zone_rx ]
        return res_dict

class LogFileParser:
    def __init__(self, verbose=False, simulation=True):
        self.verbose = verbose
        self.simulation = simulation
        self.filename = None
        self.nodes = {}
        self.result_dict = {}

    def GetSyncDelay(self, node):
        (tx_sync, rx_sync) = node.GetSyncTimes()
        sync_delay = []
        for (iternum, txtime) in tx_sync.iteritems():
            # For each SYNC message tx by node, find the last corresponding Rx
            # SYNC at neighbors.
            rx_times = []
            for neighbor_id in node.ntable:
                neighbor = self.nodes.get(neighbor_id)
                if neighbor == None:
                    continue
                (ntx_sync, nrx_sync) = neighbor.GetSyncTimes()
                if iternum not in nrx_sync:
                    # Neighbor did not receive any SYNC with iternum
                    continue
                if node.id not in nrx_sync[iternum]:
                    # neighbor did not receive SYNC from this node
                    continue
                rx_times.append(nrx_sync[iternum][node.id])
            if rx_times == []:
                rx_times.append(txtime)
            max_rx = max(rx_times)
            if max_rx > txtime:
                sync_delay.append(max_rx - txtime)
            else:
                sync_delay.append(0)
        return sync_delay

    def GetMutexConflicts(self, node):
        conflicts = 0
        conflicting_ids = []
        for neighbor_id in node.ntable:
            neighbor = self.nodes.get(neighbor_id)
            if neighbor == None:
                continue
            for selfiter in range(len(node.appstate.release_times)):
                for nbriter in range(len(neighbor.appstate.release_times)):
                    if node.Overlaps(neighbor, selfiter, nbriter):
                        conflicts += 1
                        conflicting_ids.append(neighbor_id)
        return (conflicts, conflicting_ids)

    def GetNodeTxRxCount(self, node):
        (txcount, rx, rxlist) = node.GetTxRxCount()
        rxcount = float(rx)
        for neighbor_id in rxlist:
            neighbor = self.nodes.get(neighbor_id)
            if neighbor == None:
                continue
            if len(neighbor.ntable) > 0:
                rxcount = rxcount + (1.0/len(neighbor.ntable))
            else:
                rxcount = rxcount + 1.0
        return (txcount, rxcount)

    def ParseFile(self, filename):
        self.nodes = {}
        self.result_dict = {}
        gc.collect()
        self.filename = filename
        ev = EventFields(self.verbose, self.simulation)
        f = open(filename, 'r')
        if self.verbose:
            print 'Opened file: ', filename
        for line in f:
            logentry = ev.Get(line)
            nodeid = logentry['node']
            if nodeid not in self.nodes:
                self.nodes[nodeid] = Node(nodeid, self.verbose)
            self.nodes[nodeid].UpdateState(logentry)

    def GetStats(self):
        total_tx = 0.0
        total_rx = 0.0
        result = {}
        if self.verbose:
            print 'Stats for each node:'
        for (id, n) in self.nodes.iteritems():
            nodestats = n.GetStats()
            nodestats['conflicts'] = self.GetMutexConflicts(n)
            nodestats['id'] = id
            nodestats['syncdelay'] = self.GetSyncDelay(n) 
            result[id] = nodestats
            (txcount, rxcount) = self.GetNodeTxRxCount(n)
            total_tx = total_tx + txcount
            total_rx = total_rx + rxcount
            if self.verbose:
                print 'Node:', id, nodestats
        if self.verbose:
            print 'Total messages: Tx =', total_tx, 'Rx=', total_rx
        total_msg = { 'tx' : total_tx, 'rx' : total_rx }
        return (result, total_msg)

######################################################################
# Testing + stand-alone use to parse files from a list given manually 
######################################################################

def CombineLogs(logfile, nodes):
    filename = logfile + '.txt'
    print 'Combining logs into ', filename
    outfile = open(filename, 'w')
    loglist = [ ]
    # First read all the files into memory
    for n in nodes:
        filename = logfile + '_' + str(n) + '.txt'
        print 'Reading file: ', filename
        lfile = open(filename, 'r')
        for line in lfile:
            fields = line.split()
            tstamp = int(fields[0])
            loglist.append( (tstamp, line) )
        lfile.close()
    # Now sort list of logs
    loglist.sort()
    # Dump sorted list into outfile
    for l in loglist:
        outfile.write(l[1])
    outfile.close()

if (__name__ == '__main__'):
    try:
        longopts = ["verbose", "motes", "log="]
        opts, args = getopt.getopt(sys.argv[1:], "vml:", longopts)
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    logdir = '.'
    simulation = True
    infilename = 'out.txt'
    NODES = [ 15, 16, 17, 18, 11, 12, 13, 8 ]
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-l", "--log"):
            logdir = a
        elif o in ("-m", "--motes"):
            simulation = False
    lf = LogFileParser(verbose, simulation)
    if not simulation:
        logfile = logdir + '/MoteLog'
        CombineLogs(logfile, NODES)
        infilename = logfile + '.txt'
    else:
        infilename = logdir
    lf.ParseFile(infilename)
    (stats, tmsg) = lf.GetStats()
    print stats
    #print 'Deadlocks detected:'
    #for (n, nstat) in stats.iteritems():
    #    if nstat['deadlock'] > 0:
    #        print n
    #print 'Incomplete iterations:'
    #for (n, nstat) in stats.iteritems():
    #    if nstat['requests'] < 10:
    #        print n
