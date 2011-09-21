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
        self.lf = parser.LogFileParser(verbose)
        self.verbose = verbose
        self.sim_stats = {}
        self.tmsg_stats = {}
        self.experiments = 0
        self.runs = 0
        self.gainstr = ''
        self.lossstr = ''

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

    def GenerateResults(self, experiments, runs, loss=0, gain=None):
        # return sim_stats:
        # { exp0 : [ run0 , run1, .. ], 
        #   exp1 : [ run0 , run1, .. ], 
        #   ... }
        # Each runi is returned from ParseFile
        # runi = { nodeid0 : nodestats, 
        #          nodeid1 : nodestats, .. }
        # nodestats = { 'rt': value, 'mpcs': value, ...}
        # return tmsg_stats:
        # { exp0 : [ run0 , run1, .. ], 
        #   exp1 : [ run0 , run1, .. ] }
        # Each runi is returned from ParseFile
        # runi = { 'tx' : txcount, 
        #          'rx' : rxcount }
        self.gainstr = ''
        if gain != None:
            self.gainstr = str(gain)
        self.lossstr = str(loss)
        logdir = 'logs/camera' + self.gainstr + "/loss" + self.lossstr
        logbase = logdir + '/log_pose_' 
        self.sim_stats = {}
        self.tmsg_stats = {}
        self.experiments = experiments
        self.runs = runs
        for pose in experiments:
            print 'Generating results for pose: ', pose
            extlogbase = logbase + str(pose) + '_'
            local_stats = []
            local_tmsg = []
            for i in range(runs):
                logfilename = extlogbase + str(i) + '.txt'
                print 'Run [', i, ']'
                self.lf.ParseFile(logfilename)
                (stats, tmsg) = self.lf.GetStats()
                # Process the stats to adjust for conflicts due to pkt loss
                self._processConflicts(stats)
                if self.verbose:
                    print stats
                local_stats.append(stats)
                local_tmsg.append(tmsg)
            self.sim_stats[pose] = local_stats
            self.tmsg_stats[pose] = local_tmsg

    def PlotAppLatency(self):
        experiments = self.experiments
        runs = self.runs
        sim_stats = self.sim_stats
        plotdir = 'plots/camera' + self.gainstr + "/loss" + self.lossstr
        plotfile = plotdir + '/app_latency.txt'
        pf = open(plotfile, 'w')
        print 'Plotting total application latency vs Pose..'
        for pose in experiments:
            latency = [ ]
            for r in range(runs):
                # Calculate app latency for each run by calculating the
                # difference between the first lock acquire request in the
                # network, and the last release time across the entire network
                # of nodes.
                acquirelist = [ nstat['acquiretimes'][0] for nstat in sim_stats[pose][r].itervalues() ]
                releaselist = [ nstat['releasetimes'][-1] for nstat in sim_stats[pose][r].itervalues() ]
                min_acquire = min(acquirelist)
                max_release = max(releaselist)
                latency.append(max_release - min_acquire)
            mean_l = mean(latency)
            sd_l = sd(latency)
            writestr = 'P' + str(pose) + '\t' + str(mean_l) + '\t' + str(sd_l)
            if self.verbose:
                print writestr
            pf.write(writestr+'\n')
        pf.close()

    def PlotAppMessages(self):
        experiments = self.experiments
        runs = self.runs
        sim_stats = self.sim_stats
        plotdir = 'plots/camera' + self.gainstr + "/loss" + self.lossstr
        plotfile = plotdir + '/app_messages.txt'
        pf = open(plotfile, 'w')
        print 'Plotting total messages exchanged per node vs Pose..'
        for pose in experiments:
            messages = [ ]
            for r in range(runs):
                # Calculate total number of messages exchanged by each node in
                # this run.
                msg_per_node = [ sum(nstat['mpcs']) for nstat in sim_stats[pose][r].itervalues() ]
                avg_m = mean(msg_per_node)
                messages.append(avg_m)
            mean_m = mean(messages)
            sd_m = sd(messages)
            writestr = 'P' + str(pose) + '\t' + str(mean_m) + '\t' + str(sd_m)
            if self.verbose:
                print writestr
            pf.write(writestr+'\n')
        pf.close()

    def PlotAppViolations(self):
        # This should ideally be zero as we are assuming perfect communication
        experiments = self.experiments
        runs = self.runs
        sim_stats = self.sim_stats
        plotdir = 'plots/camera' + self.gainstr + "/loss" + self.lossstr
        plotfile = plotdir + '/app_violations.txt'
        pf = open(plotfile, 'w')
        print 'Plotting total number of lock violations vs Pose..'
        for pose in experiments:
            violations = [ ]
            for r in range(runs):
                # Get number of violations for each node in this run.
                v_per_node = [ nstat['conflicts'][0] for nstat in sim_stats[pose][r].itervalues() ]
                total_v = sum(v_per_node)/2
                violations.append(total_v)
            mean_v = mean(violations)
            sd_v = sd(violations)
            writestr = 'P' + str(pose) + '\t' + str(mean_v) + '\t' + str(sd_v)
            if self.verbose:
                print writestr
            pf.write(writestr+'\n')
        pf.close()

    def _pkterr(self, counts):
        e = 0.0
        if counts['tx'] > 0:
            e = (counts['tx'] - counts['rx'])/counts['tx']
        return (e*100)

    def PlotPktError(self):
        experiments = self.experiments
        runs = self.runs
        tmsg_stats = self.tmsg_stats
        plotdir = 'plots/camera' + self.gainstr + "/loss" + self.lossstr
        plotfile = plotdir + '/pkterr.txt'
        pf = open(plotfile, 'w')
        print 'Plotting packet errors vs Pose..'
        for pose in experiments:
            err_per_run = [ self._pkterr(counts) for counts in
                    tmsg_stats[pose] ]
            mean_err = mean(err_per_run)
            sd_err = sd(err_per_run)
            writestr = 'P' + str(pose) + '\t' + str(mean_err) + '\t' + str(sd_err)
            if self.verbose:
                print writestr
            pf.write(writestr+'\n')
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
    sim.GenerateResults(range(NUM_EXPERIMENTS), NUM_RUNS, 0)
    sim.PlotAppLatency()
    sim.PlotAppMessages()
    sim.PlotAppViolations()
    sim.PlotPktError()
    sim.GenerateResults(range(NUM_EXPERIMENTS), NUM_RUNS, 20)
    sim.PlotAppLatency()
    sim.PlotAppMessages()
    sim.PlotAppViolations()
    sim.PlotPktError()
    sim.GenerateResults(range(NUM_EXPERIMENTS), NUM_RUNS, 40)
    sim.PlotAppLatency()
    sim.PlotAppMessages()
    sim.PlotAppViolations()
    sim.PlotPktError()
    sim.GenerateResults(range(NUM_EXPERIMENTS), NUM_RUNS, 60)
    sim.PlotAppLatency()
    sim.PlotAppMessages()
    sim.PlotAppViolations()
    sim.PlotPktError()
    sim.GenerateResults(range(NUM_EXPERIMENTS), NUM_RUNS, 80)
    sim.PlotAppLatency()
    sim.PlotAppMessages()
    sim.PlotAppViolations()
    sim.PlotPktError()
