#!/usr/bin/python

import sys
import random
import getopt
import math
import worldgen as world
import ParseFile as parser
from multiprocessing import Process
import subprocess

def mean(list):
    if len(list) == 0:
        return 0.0
    avg = sum(list)/float(len(list))
    return avg

def sd(list):
    if len(list) == 0:
        return 0.0
    avg = mean(list)
    return math.sqrt(sum([(x-avg)*(x-avg) for x in list])/float(len(list)))

class Simulation:
    def __init__(self, verbose=False):
        self.topo_gen = world.TopologyFile('', 3, 0.5, verbose)
        self.lf = parser.LogFileParser(verbose)
        self.verbose = verbose
        self.strloss = '0'
        # Create soft links to pose file
        simdir = "$TOSROOT/apps/ActuationTest/Tests/sim"
        target = simdir + "/topology/gen_pose.h"
        link = "$TOSDIR/lib/actuator/gen_pose.h"
        pstr = "ln -sf " + target + " " + link
        print "Creating soft link to pose file..."
        p = subprocess.Popen(pstr, shell=True)
        p.wait()

    def Run(self, trytime, holdfactor, gridsize, densities, runs, transport,
            load, lossvalue=0, gain=None):
        simdir = "$TOSROOT/apps/ActuationTest/Tests/sim"
        numNodes = gridsize*gridsize
        # Run the simulation
        self.gridsize = gridsize
        topobase = 'topology/topo_' + str(gridsize) + '_d'
        logbase = 'logs/try' + trytime + '/hold' + holdfactor 
        logbase += '/' + transport + '/loss' + str(lossvalue)
        # Create logs directory
        pstr = "mkdir -p " + logbase
        print "Creating log directory..."
        p = subprocess.Popen(pstr, shell=True)
        p.wait()
        # Create plots directory
        plotbase = 'plots/try' + trytime + '/hold' + holdfactor 
        plotbase += '/' + transport + '/loss' + str(lossvalue)
        pstr = "mkdir -p " + plotbase
        print "Creating plots directory..."
        p = subprocess.Popen(pstr, shell=True)
        p.wait()
        logbase += '/log_' + str(gridsize) + '_d'
        print 'Running Simulation grid: ', gridsize, 'x', gridsize
        for d in range(len(densities)):
            # Create the range file
            print "Creating Range.h file..."
            rangefile = open('../Range.h', 'w')
            d_cm = int(densities[d]*100.0)
            pstr = '#ifdef RANGE_MAX\n#undef RANGE_MAX\n#endif'
            rangefile.write(pstr+'\n\n')
            pstr = '#define RANGE_MAX ' + str(d_cm)
            rangefile.write(pstr+'\n\n')
            pstr = '#define GRID_SIZE ' + str(gridsize)
            rangefile.write(pstr+'\n\n')
            pstr = '#define LOAD_L' + str(load)
            rangefile.write(pstr+'\n\n')
            pstr = '#define TEST' + trytime
            rangefile.write(pstr+'\n\n')
            pstr = '#define TEST' + holdfactor
            rangefile.write(pstr+'\n\n')
            pstr = '#ifdef PACKET_LOSS_RATE\n#undef PACKET_LOSS_RATE\n#endif'
            rangefile.write(pstr+'\n\n')
            pstr = '#define PACKET_LOSS_RATE ' + str(lossvalue)
            rangefile.write(pstr+'\n\n')
            rangefile.close()
            # Compile the app
            pstr = "cd " + simdir + "/.. ; make clean; make micaz sim"
            print "Compiling the application..."
            p = subprocess.Popen(pstr, shell=True)
            p.communicate()
            # Run the simulation
            extlogbase = logbase + str(d) + '_'
            topofilename = topobase + str(d) + '.txt'
            for i in range(runs):
                logfilename = extlogbase + str(i) + '.txt'
                print '[', densities[d], i, ']'
                args = "python ../TestSim.py -n " + str(numNodes)
                args += " -a TestP1 -t " + topofilename
                args += " -l " + logfilename
                if gain != None:
                    args += " -g " + str(gain)
                print "Cmd: ", args
                p = subprocess.Popen(args, shell=True)
                p.communicate()

    def CreateTopology(self, gridsize, densities):
        t = self.topo_gen
        topobase = 'topology/topo_' + str(gridsize) + '_d'
        idx = 0
        for d in densities:
            topofilename = topobase + str(idx) + '.txt'
            t.SetNewFile(topofilename, gridsize, d)
            t.Generate()
            idx += 1

    def GenerateResults(self, trytime, holdfactor, gridsize, densities, runs,
            transport, lossvalue=0):
        # return sim_stats:
        # { density0 : [ run0 , run1, .. ], 
        #   density1 : [ run0 , run1, .. ] }
        # Each runi is returned from ParseFile
        # runi = { nodeid0 : nodestats, 
        #          nodeid1 : nodestats, .. }
        # nodestats = { 'rt': value, 'mpcs': value, ...}
        # return tmsg_stats:
        # { density0 : [ run0 , run1, .. ], 
        #   density1 : [ run0 , run1, .. ] }
        # Each runi is returned from ParseFile
        # runi = { 'tx' : txcount, 
        #          'rx' : rxcount }
        self.strloss = str(lossvalue)
        print 'Packet Loss: ', self.strloss
        logbase = 'logs/try' + trytime + '/hold' + holdfactor 
        logbase += '/' + transport + '/loss' + self.strloss
        logbase += '/log_' + str(gridsize) + '_d'
        sim_stats = {}
        tmsg_stats = {}
        print 'Generating Results grid: ', gridsize, 'x', gridsize
        for d in range(len(densities)):
            extlogbase = logbase + str(d) + '_'
            local_stats = []
            local_tmsg = []
            for i in range(runs):
                logfilename = extlogbase + str(i) + '.txt'
                print '[', densities[d], i, ']'
                self.lf.ParseFile(logfilename)
                (stats, tmsg) = self.lf.GetStats()
                print 'Packet stats: ', tmsg
                if self.verbose:
                    print stats
                local_stats.append(stats)
                local_tmsg.append(tmsg)
            sim_stats[d] = local_stats
            tmsg_stats[d] = local_tmsg
        return (sim_stats, tmsg_stats)

    def _GetAvgLatency(self, gridsize, densities, sim_stats, runs):
        result = {}
        t = self.topo_gen
        for d in range(len(densities)):
            latency = []
            for ridx in range(runs):
                r = sim_stats[d][ridx]
                # Calculate app latency for each run by calculating the
                # difference between the first lock acquire request in the
                # network, and the last release time across the entire network
                # of nodes.
                acquirelist = [ nstat['acquiretimes'][0] for nstat in r.itervalues() ]
                releaselist = [ nstat['releasetimes'][-1] for nstat in r.itervalues() ]
                min_acquire = min(acquirelist)
                max_release = max(releaselist)
                latency.append(max_release - min_acquire)
            mean_l = mean(latency)
            sd_l = sd(latency)
            t.SetNewFile('', gridsize, densities[d])
            result[t.GetActualDensity()] = [mean_l, sd_l]
        return result

    def PlotAppLatency(self, trytime, holdfactor, grids, stats, runs,
            transport):
        plotfilename = 'plots/try' + trytime + '/hold' + holdfactor
        plotfilename += '/' + transport + '/loss' + self.strloss + '/app_latency.txt'
        plotfile = open(plotfilename, 'w')
        writestr = '# Plotting Total App Latency vs Density'
        print writestr
        plotfile.write(writestr + '\n\n')
        gridlist = [ g for g in grids.iterkeys() ]
        # Sort by grid sizes so that it is easier to plot later
        gridlist.sort()
        for gridsize in gridlist:
            #for gridsize, densities in grids.iteritems():
            densities = grids[gridsize]
            # For each gridsize plot mean app latency vs density
            writestr = '# Grid : ' + str(gridsize)
            print writestr
            plotfile.write(writestr + '\n')
            ret = self._GetAvgLatency(gridsize, densities, stats[gridsize],
                    runs)
            dlist = [ density for density in ret.iterkeys() ]
            dlist.sort()
            for d in dlist:
                rts = ret[d]
                writestr = str(d) + '\t' + str(rts[0])
                writestr += '\t' + str(rts[1])
                if self.verbose:
                    print writestr
                plotfile.write(writestr + '\n')
            plotfile.write('\n\n')
        plotfile.close()

    def _GetAvgRTvalues(self, gridsize, densities, sim_stats, runs):
        result = {}
        t = self.topo_gen
        for d in range(len(densities)):
            r = sim_stats[d][0]
            # Get avg RT per iteration for each node in this run
            rtlist = [ mean(stats['rt']) for stats in r.itervalues() ]
            # Calculate avg RT per iteration per node
            rt_mean = mean(rtlist)
            rt_sd = sd(rtlist)
            t.SetNewFile('', gridsize, densities[d])
            result[t.GetActualDensity()] = [rt_mean, rt_sd]
        return result

    def PlotRTvsDensity(self, trytime, holdfactor, grids, stats, runs,
            transport):
        plotfilename = 'plots/try' + trytime + '/hold' + holdfactor
        plotfilename += '/' + transport + '/loss' + self.strloss + '/rt_density.txt'
        plotfile = open(plotfilename, 'w')
        writestr = '# Plotting Avg Response time per node vs Density'
        print writestr
        plotfile.write(writestr + '\n\n')
        gridlist = [ g for g in grids.iterkeys() ]
        gridlist.sort()
        for gridsize in gridlist:
            #for gridsize, densities in grids.iteritems():
            densities = grids[gridsize]
            # For each gridsize plot deadlocks vs density
            writestr = '# Grid : ' + str(gridsize)
            print writestr
            plotfile.write(writestr + '\n')
            ret = self._GetAvgRTvalues(gridsize, densities,
                    stats[gridsize], runs)
            dlist = [ density for density in ret.iterkeys() ]
            dlist.sort()
            for d in dlist:
                rts = ret[d]
                writestr = str(d) + '\t' + str(rts[0])
                writestr += '\t' + str(rts[1])
                if self.verbose:
                    print writestr
                plotfile.write(writestr + '\n')
            plotfile.write('\n\n')
        plotfile.close()

    def _GetAvgConflictValues(self, gridsize, densities, sim_stats, runs):
        result = {}
        t = self.topo_gen
        for d in range(len(densities)):
            r = sim_stats[d][0]
            # Get list containing total conflicts for each node over 100
            # iterations
            clist = [ stats['conflicts'][0] for stats in r.itervalues() ]
            # Calculate total conflicts in the network over 100 iterations
            c = sum(clist)/2
            conflicts_mean = c
            t.SetNewFile('', gridsize, densities[d])
            result[t.GetActualDensity()] = [conflicts_mean, 0.0]
        return result

    def PlotConflictsVsDensity(self, trytime, holdfactor, grids, stats, runs,
            transport):
        plotfilename = 'plots/try' + trytime + '/hold' + holdfactor
        plotfilename += '/' + transport + '/loss' + self.strloss + '/conflicts_density.txt'
        plotfile = open(plotfilename, 'w')
        writestr = '# Plotting Avg Conflicts vs Density'
        print writestr
        plotfile.write(writestr + '\n\n')
        gridlist = [ g for g in grids.iterkeys() ]
        gridlist.sort()
        for gridsize in gridlist:
            #for gridsize, densities in grids.iteritems():
            densities = grids[gridsize]
            writestr = '# Grid : ' + str(gridsize)
            print writestr
            plotfile.write(writestr + '\n')
            ret = self._GetAvgConflictValues(gridsize, densities,
                    stats[gridsize], runs)
            dlist = [ density for density in ret.iterkeys() ]
            dlist.sort()
            for d in dlist:
                conflicts = ret[d]
                writestr = str(d) + '\t' + str(conflicts[0])
                writestr += '\t' + str(conflicts[1])
                if self.verbose:
                    print writestr
                plotfile.write(writestr + '\n')
            plotfile.write('\n\n')
        plotfile.close()

    def _GetActualDensities(self, gridsize, densities):
        result = []
        t = self.topo_gen
        for d in range(len(densities)):
            t.SetNewFile('', gridsize, densities[d])
            result.append( (t.GetActualDensity(), d) )
        return result

    def PlotPkterrVsDensity(self, trytime, holdfactor, grids, stats, runs,
            transport):
        # tmsg:
        # { density0 : [ run0 , run1, .. ], 
        #   density1 : [ run0 , run1, .. ] }
        # Each runi is returned from ParseFile
        # runi = { 'tx' : txcount, 
        #          'rx' : rxcount }
        plotfilename = 'plots/try' + trytime + '/hold' + holdfactor
        plotfilename += '/' + transport + '/loss' + self.strloss + '/pkterr_density.txt'
        plotfile = open(plotfilename, 'w')
        writestr = '# Plotting Pkt Error vs Density'
        print writestr
        plotfile.write(writestr + '\n\n')
        gridlist = [ g for g in grids.iterkeys() ]
        gridlist.sort()
        for gridsize in gridlist:
            densities = grids[gridsize]
            tmsg = stats[gridsize]
            writestr = '# Grid : ' + str(gridsize)
            print writestr
            plotfile.write(writestr + '\n')
            dlist = self._GetActualDensities(gridsize, densities)
            dlist.sort()
            for d in dlist:
                # Assume only 1 run for each density
                counts = tmsg[d[1]][0]
                pkterr = 0.0
                if counts['tx'] > 0:
                    pkterr = (counts['tx']-counts['rx'])/counts['tx']
                writestr = str(d[0]) + '\t' + str(int(pkterr*100))
                if self.verbose:
                    print writestr
                plotfile.write(writestr + '\n')
            plotfile.write('\n\n')
        plotfile.close()

    def PlotRT(self, trytime, holdfactor, gridsize, densities, sim_stats,
            runs, transport):
        plotfilename = 'plots/try' + trytime + '/hold' + holdfactor
        plotfilename += '/' + transport + '/loss' + self.strloss + '/rt_data_' + str(gridsize) + '.txt'
        plotfile = open(plotfilename, 'w')
        writestr = '# Plotting RT vs node id'
        print writestr
        for d in range(len(densities)):
            writestr = '# Grid, Density: ' + str(gridsize)
            writestr += ', ' + str(densities[d])
            print writestr
            plotfile.write(writestr + '\n')
            for nodeid in range(gridsize*gridsize):
                r = sim_stats[d][0]
                # Calculate mean RT per iteration and stddev for this node
                mpcs_mean = mean(r[nodeid]['rt'])
                mpcs_sd = sd(r[nodeid]['rt'])
                writestr = str(nodeid) + '\t' + str(mpcs_mean)
                writestr += '\t' + str(mpcs_sd)
                if self.verbose:
                    print writestr
                plotfile.write(writestr + '\n')
            plotfile.write('\n\n')
        plotfile.close()

    def PlotMPCS(self, trytime, holdfactor, gridsize, densities, sim_stats,
            runs, transport):
        plotfilename = 'plots/try' + trytime + '/hold' + holdfactor
        plotfilename += '/' + transport + '/loss' + self.strloss + '/data_' + str(gridsize) + '.txt'
        plotfile = open(plotfilename, 'w')
        writestr = '# Plotting MPCS vs node id'
        print writestr
        for d in range(len(densities)):
            writestr = '# Grid, Density: ' + str(gridsize)
            writestr += ', ' + str(densities[d])
            print writestr
            plotfile.write(writestr + '\n')
            for nodeid in range(gridsize*gridsize):
                r = sim_stats[d][0]
                # Calculate mean MPCS per iteration and stddev for this node
                mpcs_mean = mean(r[nodeid]['mpcs'])
                mpcs_sd = sd(r[nodeid]['mpcs'])
                writestr = str(nodeid) + '\t' + str(mpcs_mean)
                writestr += '\t' + str(mpcs_sd)
                if self.verbose:
                    print writestr
                plotfile.write(writestr + '\n')
            plotfile.write('\n\n')
        plotfile.close()

    def _GetAvgMPCSvalues(self, gridsize, densities, sim_stats, runs):
        result = {}
        t = self.topo_gen
        for d in range(len(densities)):
            r = sim_stats[d][0]
            # Get avg RT per iteration for each node in this run
            rtlist = [ mean(stats['mpcs']) for stats in r.itervalues() ]
            # Calculate avg RT per iteration per node
            mpcs_mean = mean(rtlist)
            mpcs_sd = sd(rtlist)
            t.SetNewFile('', gridsize, densities[d])
            result[t.GetActualDensity()] = [mpcs_mean, mpcs_sd]
        return result

    def PlotMPCSvsDensity(self, trytime, holdfactor, grids, stats, runs,
            transport):
        plotfilename = 'plots/try' + trytime + '/hold' + holdfactor
        plotfilename += '/' + transport + '/loss' + self.strloss + '/mpcs_density.txt'
        plotfile = open(plotfilename, 'w')
        writestr = '# Plotting Avg MPCS vs Density'
        print writestr
        plotfile.write(writestr + '\n\n')
        #result = {}
        gridlist = [ g for g in grids.iterkeys() ]
        gridlist.sort()
        for gridsize in gridlist:
            #for gridsize, densities in grids.iteritems():
            densities = grids[gridsize]
            writestr = '# Grid : ' + str(gridsize)
            print writestr
            plotfile.write(writestr + '\n')
            ret = self._GetAvgMPCSvalues(gridsize, densities, stats[gridsize], runs)
            #for k,v in ret.iteritems():
            #    result[k] = v
            dlist = [ density for density in ret.iterkeys() ]
            dlist.sort()
            for d in dlist:
                mpcs = ret[d]
                writestr = str(d) + '\t' + str(mpcs[0])
                writestr += '\t' + str(mpcs[1])
                if self.verbose:
                    print writestr
                plotfile.write(writestr + '\n')
            plotfile.write('\n\n')
        plotfile.close()

def __test(trytime, holdfactor, verbose, runs, transport, load, loss=[0], gain=None):
    sim = Simulation(verbose)
    grids = {}
    grids = { 5 : [0.6, 0.8, 1.1, 1.2], 7 : [0.6, 0.8, 1.1, 1.2] }
    #grids = { 3 : [0.6, 0.8, 1.1, 1.2, 1.5],
    #          5 : [0.6, 0.8, 1.1, 1.2],
    #          7 : [0.6, 0.8, 1.1, 1.2],
    #          10 : [0.6, 0.8, 1.1, 1.2] }
    #if load == 4:
    #    grids = { 3 : [0.6, 0.8, 1.1, 1.2, 1.5],
    #            5 : [0.6, 0.8, 1.1],
    #            7 : [0.6, 0.8, 1.1],
    #            10 : [0.6, 0.8] }
    #elif load == 3:
    #    grids = { 3 : [0.6, 0.8, 1.1, 1.2, 1.5],
    #            5 : [0.6, 0.8, 1.1] }
    #elif load == 2:
    #    grids = { 3 : [0.6, 0.8, 1.1, 1.2, 1.5],
    #            5 : [0.6, 0.8] }
    # Create the topology files
    #sim.CreateTopology(3, grids[3])
    #sim.CreateTopology(5, grids[5])
    #sim.CreateTopology(7, grids[7])
    #sim.CreateTopology(10, grids[10])
    # Add the load suffix to transport
    transport += 'L' + str(load)
    for l in loss:
        stats = {}
        tmsg = {}
        # Now run the simulations
        #if 3 in grids:
        #    sim.Run(trytime, holdfactor, 3, grids[3], runs, transport, load, l, gain)
        #if 5 in grids:
        #    sim.Run(trytime, holdfactor, 5, grids[5], runs, transport, load, l, gain)
        #if 7 in grids:
        #    sim.Run(trytime, holdfactor, 7, grids[7], runs, transport, load, l, gain)
        #if 10 in grids:
        #    sim.Run(trytime, holdfactor, 10, grids[10], runs, transport, load, l, gain)
        # Now parse the log files
        if 3 in grids:
            (stats[3], tmsg[3]) = sim.GenerateResults(trytime, holdfactor, 3, grids[3], runs, transport, l)
        if 5 in grids:
            (stats[5], tmsg[5]) = sim.GenerateResults(trytime, holdfactor, 5, grids[5], runs, transport, l)
        if 7 in grids:
            (stats[7], tmsg[7]) = sim.GenerateResults(trytime, holdfactor, 7, grids[7], runs, transport, l)
        if 10 in grids:
            (stats[10], tmsg[10]) = sim.GenerateResults(trytime, holdfactor, 10, grids[10], runs, transport, l)
        # Now plot the results
        #if 3 in grids:
        #    sim.PlotMPCS(trytime, holdfactor, 3, grids[3], stats[3], runs, transport)
        #if 5 in grids:
        #    sim.PlotMPCS(trytime, holdfactor, 5, grids[5], stats[5], runs, transport)
        #if 7 in grids:
        #    sim.PlotMPCS(trytime, holdfactor, 7, grids[7], stats[7], runs, transport)
        #if 10 in grids:
        #    sim.PlotMPCS(trytime, holdfactor, 10, grids[10], stats[10], runs, transport)
        #if 3 in grids:
        #    sim.PlotRT(trytime, holdfactor, 3, grids[3], stats[3], runs, transport)
        #if 5 in grids:
        #    sim.PlotRT(trytime, holdfactor, 5, grids[5], stats[5], runs, transport)
        #if 7 in grids:
        #    sim.PlotRT(trytime, holdfactor, 7, grids[7], stats[7], runs, transport)
        #if 10 in grids:
        #    sim.PlotRT(trytime, holdfactor, 10, grids[10], stats[10], runs, transport)
        sim.PlotMPCSvsDensity(trytime, holdfactor, grids, stats, runs, transport)
        #sim.PlotConflictsVsDensity(trytime, holdfactor, grids, stats, runs, transport)
        sim.PlotRTvsDensity(trytime, holdfactor, grids, stats, runs, transport)
        #sim.PlotAppLatency(trytime, holdfactor, grids, stats, runs, transport)
        #sim.PlotPkterrVsDensity(trytime, holdfactor, grids, tmsg, runs, transport)

if (__name__ == '__main__'):
    try:
        opts, args = getopt.getopt(sys.argv[1:], "ve", ["verbose", "errors"])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    list_errors = False
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-e", "--errors"):
            list_errors = True
    loss = [ 20, 40, 60, 80 ]
    # Load: [1, 3]
    #__test('_dynamic', '_relax', verbose, 1, 'unreliable', 1)
    # Load: [15,25]
    #__test('_dynamic', '_relax', verbose, 1, 'unreliable', 2)
    # Load: [60,180]
    #__test('_dynamic', '_relax', verbose, 1, 'unreliable', 3)
    # Load: [300,600]
    #__test('_dynamic', '_relax', verbose, 1, 'unreliable', 4)
    # Load: [1, 3]
    __test('_dynamic', '_strict', verbose, 1, 'unreliable', 1, loss)
    # Load: [15,25]
    #__test('_dynamic', '_strict', verbose, 1, 'unreliable', 2, loss)
    # Load: [60,180]
    #__test('_dynamic', '_strict', verbose, 1, 'unreliable', 3, loss)
    # Load: [300,600]
    __test('_dynamic', '_strict', verbose, 1, 'unreliable', 4, loss)
