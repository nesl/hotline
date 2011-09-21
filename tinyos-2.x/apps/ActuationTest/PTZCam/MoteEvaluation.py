#!/usr/bin/python

import sys
import random
import getopt
import math
import ParseFile as parser

def mean(list):
    if len(list) == 0:
        return 0.0
    avg = sum(list)/float(len(list))
    return avg

def sd(list):
    avg = mean(list)
    return math.sqrt(sum([(x-avg)*(x-avg) for x in list])/float(len(list)))

NUM_EXPERIMENTS = 10
NUM_NODES = 25
NUM_RUNS = 10
ADJUST_FACTOR = 2

def getSum(C, v, N):
    sum = 0.0
    iter = C
    i = 0
    while iter > 0.01:
        sum = sum + iter
        i = i + 1
        iter = C * math.pow(v*N, i)
    return sum

class Simulation:
    def __init__(self, verbose=False):
        self.lf = parser.LogFileParser(verbose, False)
        self.verbose = verbose
        self.sim_stats = {}
        self.tmsg_stats = {}

    def _processConflicts(self, stats):
        # Calculate total number of conflicts and transactions
        all_conflicts = [ nstats['conflicts'][0] for nstats in
                stats.itervalues() ]
        total_conflicts = float(sum(all_conflicts))
        all_transactions = [ nstats['requests'] for nstats in
                stats.itervalues() ]
        total_transactions = float(sum(all_transactions))
        vrate = total_conflicts/total_transactions
        # For each node in this simulation
        for (node, nodestats) in stats.iteritems():
            if nodestats['conflicts'][0] == 0:
                continue
            # This node had some conflicts
            num_conflicts = nodestats['conflicts'][0]
            num_iter = nodestats['requests']
            # Get average iteration time for this node
            atimes = nodestats['acquiretimes']
            rtimes = nodestats['releasetimes']
            iter_times = [ rt-at for (at, rt) in zip(atimes, rtimes) ]
            mean_iter_time = mean(iter_times)
            # Get average MPCS for this node
            mean_mpcs = int(round(mean(nodestats['mpcs'])))
            num_additions = int(round(getSum(num_conflicts*ADJUST_FACTOR,vrate,ADJUST_FACTOR)))
            for i in range(num_additions):
                # Add a new iteration
                nodestats['requests'] = nodestats['requests'] + 1
                # Adjust acquire and release times
                last_atime = atimes[-1]
                last_rtime = rtimes[-1]
                new_atime = last_rtime + (3380.0/1024.0)
                new_rtime = new_atime + mean_iter_time
                atimes.append(new_atime)
                rtimes.append(new_rtime)
                # Adjust MPCS
                nodestats['mpcs'].append(mean_mpcs)

    def GenerateResults(self):
        # return sim_stats:
        # sim_stats = { nodeid0 : nodestats, 
        #               nodeid1 : nodestats, .. }
        # nodestats = { 'rt': value, 'mpcs': value, ...}
        # return tmsg_stats:
        # tmsg_stats = { 'tx' : txcount, 
        #                'rx' : rxcount }
        logfilename = 'motes/MoteLog.txt'
        self.sim_stats = {}
        self.tmsg_stats = {}
        self.lf.ParseFile(logfilename)
        (self.sim_stats, self.tmsg_stats) = self.lf.GetStats()
        # Process the stats to adjust for conflicts due to pkt loss
        #self._processConflicts(self.sim_stats)
        if self.verbose:
            print self.sim_stats
            print self.tmsg_stats

    def PlotAppLatency(self):
        sim_stats = self.sim_stats
        plotfile = 'motes/app_latency.txt'
        pf = open(plotfile, 'w')
        print 'Plotting total app latency'
        acquirelist = [ nstats['acquiretimes'][0] for nstats in
                sim_stats.itervalues() ]
        releaselist = [ nstats['releasetimes'][-1] for nstats in
                sim_stats.itervalues() ]
        min_acquire = min(acquirelist)
        max_release = max(releaselist)
        app_l = max_release - min_acquire
        pf.write(str(app_l))
        print 'App latency: ', app_l
        pf.close()

    def PlotAppMessages(self):
        sim_stats = self.sim_stats
        plotfile = 'motes/app_messages.txt'
        pf = open(plotfile, 'w')
        print 'Plotting total messages per node'
        mlist = [ sum(nstats['mpcs']) for nstats in sim_stats.itervalues() ]
        mean_m = mean(mlist)
        sd_m = sd(mlist)
        writestr = str(mean_m) + '\t' + str(sd_m)
        pf.write(writestr+'\n')
        print 'App messages: ', writestr
        pf.close()

if (__name__ == '__main__'):
    try:
        longopts = ["verbose"]
        opts, args = getopt.getopt(sys.argv[1:], "v", longopts)
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
    sim = Simulation(verbose)
    sim.GenerateResults()
    sim.PlotAppLatency()
    sim.PlotAppMessages()
