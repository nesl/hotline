#/usr/bin/python

import sys, os
import random
import getopt
import math
from multiprocessing import Process
import subprocess

# For microbenchmarks
import ParseFile
import networkx as nx
from source_route_gen_bfs import makeGraph

from ParseLogFile import *
from pfloat import *
from PlotExecSchedule import *
from dynamic_schedule import *

import scipy.io as sio
import numpy as np

def mean(list):
    if len(list) == 0:
        return 0.0
    avg = sum(list)/float(len(list))
    return avg

def sd(list):
    avg = mean(list)
    return math.sqrt(sum([(x-avg)*(x-avg) for x in list])/float(len(list)))

def vectordiff(x, y):
    return map(lambda x: x[0]-x[1], zip(x,y))

def norm(list):
    return math.sqrt(sum(map(lambda x: x*x, list)))

class Results:
    def __init__(self, simObject, verbose=False):
        self.verbose = verbose
        self.sim = simObject
        # These variables are set later
        self.deploymentdir = ""
        self.expdir = ""
        self.microdir = ""  # Directory storing micro-benchmarks
        self.act_est = {}   # Dictionary of actuator estimates
        self.events = {}    # List of user entry/exit events
        self.min_start = 0  # Start offset of estimation process
        self.max_end = 0    # End time of estimation process
        self.opt_est = []   # Optimal estimates
        self.init_cost = 0  # Starting value of cost function
        self.M = 0          # Number of actuators
        self.N = 0          # Number of sensors
        self.latencies = [] # List of latency numbers for each simulation run

    def setPythonPath(self):
        newPath = self.sim.origPythonPath + self.expdir + ':'
        print 'Setting PYTHONPATH to ', newPath
        os.environ['PYTHONPATH'] = newPath

    def resetPythonPath(self):
        print 'Resetting PYTHONPATH.'
        os.environ['PYTHONPATH'] = self.sim.origPythonPath

    def _createDir(self, dirname):
        pstr = "mkdir -p " + dirname
        p = subprocess.Popen(pstr, shell=True)
        p.wait()

    def _createPlotRunDir(self, exp, plotdir_r):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus',
                'HierFastConsensus' ]
        if exp not in validlist:
            return
        print 'Creating plots directory: ', plotdir_r
        self._createDir(plotdir_r)

    def GroupActuatorEstimates(self, exp, nodes):
        # Create a dictionary of estimates from the perspective of
        # actuators. It consists of M elements, one for each actuator
        # 0: { n0: [], n1:[], .., nN:[] }
        # 1: { n0: [], n1:[], .., nN:[] }
        # M-1: { n0: [], n1:[], .., nN:[] }
        self.act_est = {}
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus',
                'HierFastConsensus']
        if exp not in validlist:
            return
        start_times = []
        for (n, objn) in nodes.iteritems():
            # n : sensor node
            # objn : instance of class Node
            start_times.append(objn.appstate.acquire_times[0])
            for (id, estimates) in objn.estimates.iteritems():
                # id : actuator
                # estimates : list of estimates for actuator 'id' by sensor
                # 'n' where each element is e = {...}
                if id not in self.act_est:
                    self.act_est[id] = {}
                self.act_est[id][n] = estimates
        # Now find the min start time of the estimate procedure
        #start_times = [ min([estimates[0]['time'] for estimates in
        #    nestimates.itervalues()]) for nestimates in self.act_est.itervalues() ]
        end_times = [ max([estimates[-2]['time'] for estimates in
            nestimates.itervalues()]) for nestimates in self.act_est.itervalues() ]
        self.min_start = min(start_times)
        if exp == 'Cyclic':
            # Timer offset after first ACQUIRE
            self.min_start += 60
        self.max_end = max(end_times)
        self.M = len(self.act_est)
        self.N = len(nodes)
        if exp == 'HierFastConsensus':
            # 'nodes' includes both sensors and actuators, so subtract M to
            # get number of senors
            self.N -= self.M
        print 'Number of actuators:', self.M
        print 'Number of sensors:', self.N
        print 'Start time of estimation process:', self.min_start
        print 'End time of estimation process:', self.max_end

    def GroupEvents(self, exp, nodes):
        # Create a dictionary of events across complete network keyed by
        # iteration number so that it is easy to use later.
        # <iteration1> : { n0:v0, ..., nN:vN }
        # <iteration2> : { n0:v0, ..., nN:vN }
        self.events = {}
        validlist = [ 'FastCyclic' ]
        if exp not in validlist:
            return
        for (n, objn) in nodes.iteritems():
            for (iternum, value) in objn.appstate.events.iteritems():
                if iternum not in self.events:
                    self.events[iternum] = {}
                self.events[iternum][n] = value

    def GetOptimizers(self, r):
        optdir = self.deploymentdir + '/run' + str(r)
        optfile = optdir + '/optimal_values.mat'
        f = open(optfile, 'r')
        self.opt_est = []
        for line in f:
            val = float(line.strip())
            self.opt_est.append(int(val))
        f.close()
        print 'Optimal values:', self.opt_est

    def GetInitialCost(self, r):
        # Load the matlab file with simulation parameters
        matfilename = self.deploymentdir + '/simvar.matlab.mat'
        params = sio.loadmat(matfilename)
        Phi = params['Phi']
        # This is the worst-case cost assuming all the users are in the room
        # at initialization.
        L = np.reshape(params['u'][r,:], [1, self.N])
        L = np.floor(L)
        cost = Phi - L
        self.init_cost = np.dot(cost, cost.T)[0,0]
        print 'Starting value of objective fn:', self.init_cost

    def PlotEstimates(self, exp, plotdir):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        print' Plotting estimates for each actuator'
        for (id, nestimates) in self.act_est.iteritems():
            plotname = plotdir + '/' + 'estimate_' + str(id) + '.dat'
            plotf = open(plotname, 'w')
            for (n, estimates) in nestimates.iteritems():
                plotstr = '# Node ' + str(n)
                plotf.write(plotstr + '\n\n')
                for e in estimates:
                    plotstr = str(e['time']-self.min_start) + '\t'
                    plotstr += str(e['iteration']) + '\t'
                    plotstr += str(int(round(e['value'])))
                    plotf.write(plotstr + '\n')
                plotf.write('\n')
            plotf.close()

    def _getNumIterations(self):
        #iterlist = [ min([len(elist) for elist in n_est.itervalues()]) for
        #        n_est in self.act_est.itervalues() ]
        iterlist = [ max([len(elist) for elist in n_est.itervalues()]) for
                n_est in self.act_est.itervalues() ]
        return max(iterlist)

    def _getLocalEstimateI(self, exp, node, i):
        # Return the estimate of each actuator variable by 'node' in 'i'th
        # iteration.
        est_i = []
        for j in range(self.M):
            if node in self.act_est[j]:
                # 'node' estimated for actuator 'j'
                try:
                    est_i.append(self.act_est[j][node][i]['value'])
                except IndexError:
                    # In case 'node' did not reach iteration 'i' in
                    # simulations with adaptive iterations. So, use the last
                    # estimate at this 'node'.
                    est_i.append(self.act_est[j][node][-1]['value'])
                    #est_i.append(0) -- original
            else:
                # 'node' is not influenced by actuator 'j', so it did not
                # estimate its control input.
                est_i.append(0)
        return est_i

    def PlotLocalCost(self, exp, r, plotdir):
        validlist = [ 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        print' Plotting local cost at each node...'
        # Get the max number of iterations that were completed by all nodes in
        # the simulation
        num_iter = self._getNumIterations()
        # Load the matlab file with simulation parameters
        matfilename = self.deploymentdir + '/simvar.matlab.mat'
        params = sio.loadmat(matfilename)
        A = params['Model']
        Phi = params['Phi']
        L = np.reshape(params['u'][r,:], [1, self.N])
        L = np.floor(L)
        for n in range(self.N):
            # For each node n
            plotname = plotdir + '/' + 'local_cost_'
            plotname += str(n) + '.dat'
            plotf = open(plotname, 'w')
            plotstr = ''
            for i in range(num_iter):
                # For each iteration i, plot the local component of objective fn
                est_i = self._getLocalEstimateI(exp, n, i)
                I = np.reshape(est_i, [self.M, 1])
                f1 = np.dot(A[n,:],I)[0]
                cost = f1 + Phi[0,n] - L[0,n]
                val = cost * cost
                if i in self.events:
                    # User 'n' entered/exited. Change in desired light intensity
                    # such that it is incorporated into cost fn for next iteration.
                    if n in self.events[i]:
                        user = self.events[i][n]
                        L[0,n] = max(user*L[0,n], Phi[0,n]) 
                if i == (num_iter-1):
                    print 'Local cost (%d): %s'%(n,str(val))
                plotstr = str(i) + '\t' + str(val)
                plotf.write(plotstr + '\n')
            plotf.close()

    def _getEstimateI(self, exp, i):
        est_i = []
        if exp in [ 'Consensus' ]:
            for j in range(self.M):
                est_i.append(mean([elist[i]['value'] for elist in
                    self.act_est[j].itervalues()]))
        elif exp in [ 'FastCyclic' ]:
            # Select the latest estimate for actuator j in this iteration i
            for j in range(self.M):
                e = [ elist[i] if i<len(elist) else elist[-1] for elist in
                    self.act_est[j].itervalues() ]
                etimes = [ el['time'] for el in e ]
                idx = etimes.index(max(etimes))
                if self.verbose:
                    print '[Iter %d] Getting estimate for actuator %d'%(i,j)
                    print 'Time:', etimes[idx]
                est_i.append(e[idx]['value'])
        elif exp in [ 'FastConsensus' ]:
            for j in range(self.M):
                e = [ elist[i]['value'] for elist in
                    self.act_est[j].itervalues() ]
                nz_e = map(lambda x: 1 if (x!=0) else 0, e) 
                if self.verbose:
                    print '[Iter %d] Getting estimate for actuator %d'%(i,j)
                    print 'Sum:', sum(e)
                    print 'Non-zero entries:', sum(nz_e)
                try:
                    est_i.append(sum(e)/sum(nz_e))
                except ZeroDivisionError:
                    est_i.append(0)
        elif exp in [ 'HierFastConsensus' ]:
            # Only actuator (j+self.N) contains relevant estimates
            est_i = [ self.act_est[j][j+self.N][i]['value'] for j in range(self.M) ]
        elif exp in [ 'Cyclic' ]:
            # Only Node 0 estimates matter
            est_i = [ self.act_est[j][0][i]['value'] for j in range(self.M) ]
        return est_i

    def _getTime(self, exp, i, use_max=True):
        iterlist = [ ]
        if exp in [ 'Consensus', 'FastCyclic', 'FastConsensus', 'HierFastConsensus' ]:
            for n_est in self.act_est.itervalues():
                i_times = []
                for elist in n_est.itervalues():
                    if i < len(elist):
                        i_times.append(elist[i]['time'])
                if len(i_times) > 0:
                    # BIG CHANGE: min to max
                    iterlist += [ max(i_times) ]
            #iterlist = [ min([elist[i]['time'] for elist in n_est.itervalues()])
            #        for n_est in self.act_est.itervalues() ]
        elif exp in [ 'Cyclic' ]:
            # Any actuator, Node 0, i_th iteration
            iterlist = [ self.act_est[0][0][i]['time'] ]
        if len(iterlist) > 0:
            if use_max:
                return max(iterlist)
            else:
                return min(iterlist)
        else:
            return 0

    def PlotEstimateDistance(self, exp, ops, plotdir):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        eventlist = self.sim.extractEventInfo(exp, ops)
        if eventlist != None:
            # Currently, can not plot this for simulations with events as the
            # value of optimizer changes with events.
            return
        print' Plotting estimate distance from optimal values'
        plotname = plotdir + '/' + 'estimate_distance.dat'
        plotf = open(plotname, 'w')
        plotstr = ''
        # Get the min number of iterations that were completed by all nodes in
        # the simulation
        num_iter = self._getNumIterations()
        norm_opt = norm(self.opt_est)
        print 'Norm of optimizer:', norm_opt
        for i in range(num_iter):
            # For each iteration i, plot the normalized distance of i_th
            # estimate from the optimal estimate
            est_i = self._getEstimateI(exp, i)
            norm_diff = norm(vectordiff(est_i, self.opt_est))
            t = self._getTime(exp, i)
            val = norm_diff/norm_opt
            delta = t-self.min_start
            plotstr = str(delta) + '\t'
            plotstr += str(i) + '\t'
            plotstr += str(val)
            plotf.write(plotstr + '\n')
        plotf.close()

    def __getValidCount(self, objn_dict, i):
        if i in objn_dict:
            return objn_dict[i]
        else:
            return objn_dict[max(objn_dict.keys())]

    def _getMsgsAt(self, exp, nodes, i):
        validlist = [ 'Cyclic', 'FastCyclic', 'FastConsensus' ]
        if exp not in validlist:
            return (0, 0)
        if exp == 'Cyclic':
            return (mean([ self.__getValidCount(objn.cum_token_msgs,i+1) for objn in
                nodes.itervalues() ]), 0)
        else:
            # For 'FastCyclic' and 'FastConsensus'
            msgs = mean([ self.__getValidCount(objn.cum_msgs,i+1) for objn in nodes.itervalues() ])
            syncmsgs_mhop = mean([
                self.__getValidCount(objn.cum_sync_msgs,i+1)*abs(len(objn.ntable)-1) for objn in nodes.itervalues() ])
            return (msgs, syncmsgs_mhop)
    
    def _getLinkPktsAt(self, exp, nodes, i):
        validlist = [ 'Cyclic' ]
        if exp not in validlist:
            return 0
        if exp == 'Cyclic':
            return mean([ objn.cum_token_pkts[i+1] for objn in nodes.itervalues() ])

    def _getActualIterations(self, exp, i):
        if exp == 'Cyclic':
            return i
        else:
            # In other simulations, iteration count starts at 1
            return i+1

    def _getSensorValues(self, nodes, mtime):
        retvalues = {}
        mt = int(mtime)
        for (n,objn) in nodes.iteritems():
            retvalues[n] = 0
            for (t,sval) in objn.sensorvalues.iteritems():
                if t >= mt:
                    retvalues[n] = sval
                    break;
        return retvalues

    def _plotUserError(self, L, cost, plotdir, mode, tag):
        print 'Plotting error in actual and user-specified intensities...',tag
        plotname = plotdir + '/' + 'user_error.dat'
        plotf = open(plotname, mode)
        plotstr = ''
        errlist = map(abs, ((cost*100)/L)[0,:])
        meanerr = mean(errlist)
        plotstr = '\n# %s\n'%(tag)
        plotf.write(plotstr)
        plotstr = str(meanerr) + '\t'
        plotstr += str(sd(errlist)) + '\n'
        plotf.write(plotstr)
        plotf.close()
        return meanerr

    def PlotObjectiveFn(self, exp, ops, nodes, r, plotdir, factor):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus',
                'HierFastConsensus' ]
        if exp not in validlist:
            return
        rettime = 0
        print 'Plotting objective function...'
        plotname = plotdir + '/' + 'objective_fn.dat'
        plotf = open(plotname, 'w')
        plotstr = ''
        # Get the min number of iterations that were completed by all nodes in
        # the simulation
        num_iter = self._getNumIterations()
        # Load the matlab file with simulation parameters
        matfilename = self.deploymentdir + '/simvar.matlab.mat'
        params = sio.loadmat(matfilename)
        A = params['Model']
        Phi = params['Phi']
        L = np.reshape(params['u'][r,:], [1, self.N])
        L = np.floor(L)
        if self.verbose:
            print 'Sensor values:', L[0,:]
            print 'Ambient values:', Phi[0,:]
        found = False
        e = {}
        e['tpi'] = []
        e['mepi'] = []
        e['lepi'] = []
        check_iter = 100
        #if 'static' in ops:
        #    seqlist = self.sim.extractSequenceInfo(exp, ops)
        #    if seqlist != None:
        #        check_iter = 400
        #    elif 'nodeid' in ops:
        #        check_iter = 400
        for i in range(num_iter):
            # For each iteration i, plot the current value of objective fn
            est_i = self._getEstimateI(exp, i)
            I = np.reshape(est_i, [self.M, 1])
            f1 = np.dot(A,I).reshape([1, self.N])
            cost = f1 + Phi - L
            val = np.dot(cost, cost.T)[0,0]
            if i in self.events:
                # Some user entered/exited. Change in desired light intensity
                # such that it is incorporated into cost fn for next iteration.
                for (n,user) in self.events[i].iteritems():
                    L[0,n] = max(user*L[0,n], Phi[0,n]) 
            if i == (num_iter-1):
                print 'Estimate (%d): %s'%(i,str(est_i))
                print 'Cost vector:', cost
                print 'Value:', val
            t = self._getTime(exp, i)
            delta = t-self.min_start
            if i < check_iter:
                e['tpi'].append(delta)
                e['mepi'].append(self._getMsgsAt(exp, nodes, i))
                e['lepi'].append(self._getLinkPktsAt(exp, nodes, i))
            if not found:
                if val < (factor*self.init_cost):
                    e['time'] = delta
                    e['iter'] = self._getActualIterations(exp, i)
                    e['msgs'] = self._getMsgsAt(exp, nodes, i)
                    e['linkpkts'] = self._getLinkPktsAt(exp, nodes, i)
                    e['usererror'] = self._plotUserError(L, cost, plotdir, 'w', 'At Optimal')
                    found = True
            plotstr = str(delta) + '\t'
            plotstr += str(i) + '\t'
            plotstr += str(val)
            if exp in [ 'FastCyclic', 'Consensus', 'FastConsensus', 'HierFastConsensus' ]:
                dmin = self._getTime(exp, i, False) - self.min_start
                plotstr += '\t' + str(dmin)
            plotf.write(plotstr + '\n')
        plotf.close()
        if 'time' not in e:
            print 'Not found. Factor %f too low.'%(factor)
        self.latencies.append(e)
        self._plotUserError(L, cost, plotdir, 'a', 'At End')

    def SaveSchedule(self, exp, ops, nodes, plotdir_r, max_iters=10):
        validlist = [ 'FastCyclic' ]
        if exp not in validlist:
            return
        #if 'dynamic' not in ops:
        #    return
        plotfile = plotdir_r + '/iteration_step.txt'
        ExtractDynamicSchedule(nodes, self.deploymentdir, plotfile, max_iters,
                self.verbose)
        #for i in range(10):
        #    icount = i+1
        #    plotfile = plotdir_r + '/schedule'+ str(icount) +'.txt'
        #    plotf = open(plotfile, 'w')
        #    revsched = {}
        #    for (n,objn) in nodes.iteritems():
        #        revsched[objn.schedule[icount]] = n
        #    times = revsched.keys()
        #    times.sort()
        #    pr = 0
        #    for t in times:
        #        plotstr = str(revsched[t]) + '\t' + str(pr)
        #        plotf.write(plotstr+'\n')
        #        pr += 1
        #    plotf.close()

    def _mhopAdjustSync(self, do_mhop, objn, e):
        t = [int(math.floor(e['time']))]
        if do_mhop:
            if e['sync']:
                return t*(len(objn.ntable) if len(objn.ntable)>0 else 1)
        return t

    def PlotMessages(self, exp, ops, nodes, plotdir, r):
        validlist = [ 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        do_mhop = False
        if 'mhop' in ops:
            do_mhop = True
        print' Plotting total msg count per sec for run', r
        # Get start and end times of simulation for this run
        start_time = int(math.floor(min([ min(objn.tx[0]['time'],objn.rx[0]['time']) for objn in
            nodes.itervalues()] )))
        end_time = int(math.ceil( max(
            [ max(objn.tx[-1]['time'],objn.rx[-1]['time']) 
                for objn in nodes.itervalues() ] )))
        print 'Start: %d End: %d'%(start_time, end_time)
        plotname = plotdir + '/' + 'msg_exch.dat'
        plotf = open(plotname, 'w')
        plotstr = ''
        # Keep count of total number of messages exchanged in the network each
        # second.
        msgs = [0]*(end_time-start_time+1)
        for objn in nodes.itervalues():
            # n : sensor node
            # objn : instance of class Node
            txlist = []
            rxlist = []
            for e in objn.tx:
                txlist += self._mhopAdjustSync(do_mhop, objn, e)
            for e in objn.rx:
                rxlist += self._mhopAdjustSync(do_mhop, objn, e)
            for t in txlist:
                idx = t - start_time
                msgs[idx] = msgs[idx] + 1
            for t in rxlist:
                idx = t - start_time
                msgs[idx] += 1
        for t in range(len(msgs)):
            plotstr = str(t) + '\t' + str(msgs[t])
            plotf.write(plotstr + '\n')
        plotf.close()

    def PlotMeanLatency(self, exp, ops, plotdir):
        validlist = [ 'FastCyclic', 'Cyclic', 'FastConsensus' ]
        if exp not in validlist:
            return
        eventlist = self.sim.extractEventInfo(exp, ops)
        if eventlist != None:
            # This metric does not make sense for simulations with events.
            return
        print 'Plotting mean latencies across all the runs.'
        plotfile = plotdir + '/mean_latency.dat'
        ltime = [ el['time'] if 'time' in el else 0 for el in self.latencies ]
        liter = [ el['iter'] if 'iter' in el else 0 for el in self.latencies ]
        if sum(ltime) == 0:
            print 'No latencies found.'
            return
        plotf = open(plotfile, 'w')
        mtime = mean(ltime)
        stdtime = sd(ltime)
        miter = mean(liter)
        stditer = sd(liter)
        plotstr = str(mtime) + '\t' + str(stdtime)
        plotstr += '\t' + str(miter) + '\t' + str(stditer)
        print 'Performance: Latency %f %f'%(mtime,stdtime)
        print 'Performance: Iterations %f %f'%(miter,stditer)
        plotf.write(plotstr+'\n')
        plotf.close()

    def PlotPerIterationMetrics(self, exp, ops, plotdir):
        validlist = [ 'FastCyclic', 'Cyclic', 'FastConsensus' ]
        if exp not in validlist:
            return
        eventlist = self.sim.extractEventInfo(exp, ops)
        if eventlist != None:
            # This metric does not make sense for simulations with events.
            return
        if 'mepi' not in self.latencies[0]:
            return
        if 'tpi' not in self.latencies[0]:
            return
        if 'lepi' not in self.latencies[0]:
            return
        print 'Plotting mean TPI and MEPI across all the runs.'
        plotfile = plotdir + '/mean_iter_metric.dat'
        icount = len(self.latencies[0]['mepi'])
        lmepi = [ el['mepi'][-1][0]/icount for el in self.latencies ]
        lsyncmepi = [ el['mepi'][-1][1]/icount for el in self.latencies ]
        ltpi = [ el['tpi'][-1]/icount for el in self.latencies ]
        plotf = open(plotfile, 'w')
        total_msgs = lmepi
        if 'mhop' in ops:
            total_msgs = map(lambda x: x[0]+x[1], zip(lmepi, lsyncmepi))
        mmsgs = mean(total_msgs)
        stdmsgs = sd(total_msgs)
        plotstr = str(mmsgs) + '\t' + str(stdmsgs)
        print 'MEPI @%d: Messages %f %f'%(icount,mmsgs,stdmsgs)
        plotf.write('# Messages exchanged per iteration (MEPI) per controller @%d\n'%(icount))
        plotf.write(plotstr+'\n\n')
        mpkts = mean(ltpi)
        stdpkts = sd(ltpi)
        plotstr = str(mpkts) + '\t' + str(stdpkts)
        print 'TPI @%d: Time %f %f'%(icount,mpkts,stdpkts)
        plotf.write('# Time per iteration (TPI) per controller @%d\n'%(icount))
        plotf.write(plotstr+'\n\n')
        # Now write down the values for low iteration count as well
        icount = 10
        lmepi = [ el['mepi'][icount-1][0]/icount for el in self.latencies ]
        lsyncmepi = [ el['mepi'][icount-1][1]/icount for el in self.latencies ]
        ltpi = [ el['tpi'][icount-1]/icount for el in self.latencies ]
        total_msgs = lmepi
        if 'mhop' in ops:
            total_msgs = map(lambda x: x[0]+x[1], zip(lmepi, lsyncmepi))
        mmsgs = mean(total_msgs)
        stdmsgs = sd(total_msgs)
        plotstr = str(mmsgs) + '\t' + str(stdmsgs)
        print 'MEPI @%d: Messages %f %f'%(icount,mmsgs,stdmsgs)
        plotf.write('# Messages exchanged per iteration (MEPI) per controller @%d\n'%(icount))
        plotf.write(plotstr+'\n\n')
        mpkts = mean(ltpi)
        stdpkts = sd(ltpi)
        plotstr = str(mpkts) + '\t' + str(stdpkts)
        print 'TPI @%d: Time %f %f'%(icount,mpkts,stdpkts)
        plotf.write('# Time per iteration (TPI) per controller @%d\n'%(icount))
        plotf.write(plotstr+'\n')
        plotf.close()
        plotfile = plotdir + '/tpi_metric.dat'
        plotf = open(plotfile, 'w')
        plotf.write('# Time per iteration (TPI) vs. iterations\n')
        icount = len(self.latencies[0]['tpi'])
        for mu in range(icount):
            ltpi = [ el['tpi'][mu]/(mu+1) for el in self.latencies ]
            mpkts = mean(ltpi)
            stdpkts = sd(ltpi)
            plotstr = str(mu+1) + '\t' + str(mpkts) + '\t' + str(stdpkts)
            plotf.write(plotstr+'\n')
        plotf.close()

    def PlotMeanCost(self, exp, ops, plotdir):
        validlist = [ 'FastCyclic', 'Cyclic', 'FastConsensus' ]
        if exp not in validlist:
            return
        eventlist = self.sim.extractEventInfo(exp, ops)
        if eventlist != None:
            # This metric does not make sense for simulations with events.
            return
        print 'Plotting mean messages/pkts exchanged across all the runs.'
        plotfile = plotdir + '/mean_messages.dat'
        lmsgs = [ el['msgs'][0] if 'msgs' in el else 0 for el in self.latencies ]
        lsyncmsgs = [ el['msgs'][1] if 'msgs' in el else 0 for el in self.latencies ]
        lpkts = [ el['linkpkts'] if 'linkpkts' in el else 0 for el in self.latencies ]
        if lmsgs == [] or lpkts == []:
            print 'No messages/packets found. Try decreasing the FACTOR.'
            return
        plotf = open(plotfile, 'w')
        total_msgs = lmsgs
        if 'mhop' in ops:
            total_msgs = map(lambda x: x[0]+x[1], zip(lmsgs, lsyncmsgs))
        mmsgs = mean(total_msgs)
        stdmsgs = sd(total_msgs)
        plotstr = str(mmsgs) + '\t' + str(stdmsgs)
        print 'Cost: Messages %f %f'%(mmsgs,stdmsgs)
        plotf.write('# Messages exchanged per controller\n')
        plotf.write(plotstr+'\n\n')
        mpkts = mean(lpkts)
        stdpkts = sd(lpkts)
        plotstr = str(mpkts) + '\t' + str(stdpkts)
        print 'Cost: Link packets %f %f'%(mpkts,stdpkts)
        plotf.write('# Link packets exchanged per controller\n')
        plotf.write(plotstr+'\n')
        plotf.close()

    def PlotSchedule(self, exp, ops, nodes, plotdir, startiter=0):
        plotfilename = plotdir + '/plot.pdf'
        #PlotSchedule(nodes, plotfilename, startiter, self.verbose)

    def _getActualDensity(self, topofile, N):
        G = makeGraph(topofile, N)
        return (2*G.number_of_edges())/float(N)

    def PlotvsDensity(self, exp, ops, allvalues, outfilename):
        validlist = [ 'FastCyclic' ]
        if exp not in validlist:
            return
        seqlist = self.sim.extractSequenceInfo(exp, ops)
        seqlist = self.sim.extractSequenceInfo(exp, ops)
        outdir = self.microdir
        if seqlist != None:
            # First create this dir for sequence.
            # WARNING: It can only handle one sequence number at a time.
            seqnum = seqlist[0]
            outdir += '/seq' + str(seqnum)
            self._createDir(outdir)
        outfile = outdir + "/" + outfilename
        print 'Printing -', outfile
        outf = open(outfile, 'w')
        revalues = {}
        for (n,nvalues) in allvalues.iteritems():
            # For each grid size - n x n
            revalues[n] = {}
            for (d,dvalues) in nvalues.iteritems():
                for (l,lvalue) in dvalues.iteritems():
                    if l not in revalues[n]:
                        revalues[n][l] = {}
                    revalues[n][l][d] = lvalue
        nlist = [ n for n in revalues.iterkeys() ]
        nlist.sort()
        for n in nlist:
            # For each grid size - n x n
            nvalues = revalues[n]
            llist = [ l for l in nvalues.iterkeys() ]
            llist.sort()
            for l in llist:
                lvalues = nvalues[l]
                print >>outf, '# Grid - %d, Loss - %d'%(n,l)
                dlist = [ d for d in lvalues.iterkeys() ]
                dlist.sort()
                for d in dlist:
                    deployname = "/nodes" + str(n) + "degree" + str(d)
                    self.deploymentdir = self.sim.deployments + deployname
                    topofile = self.deploymentdir + "/topology.txt"
                    density = self._getActualDensity(topofile, n*n)
                    dvalue = lvalues[d]
                    print >>outf, '%f\t%f\t%f'%(density,dvalue[0],dvalue[1])
                print >>outf, '\n'
        outf.close()

    def Generate(self, elist, nlist, dlist, runs, factor, macro=True, micro=False):
        lparser = Parser(self.verbose)
        microlp = ParseFile.LogFileParser(self.verbose)
        for (exp, oplist) in elist.iteritems():
            for ops in oplist:
                # Setup commonly used filename variables
                self.expdir = self.sim.rootdir + "/" + exp
                simdir = self.expdir + "/sim"
                print '================================================='
                print 'Experiment: ', exp
                print 'Options -- ', ops
                self.setPythonPath()
                maxid = len(ops)
                losslist = self.sim.extractLossInfo(exp, ops)
                if losslist != None:
                    maxid -= 1
                else:
                    losslist = ['default']
                periodlist = self.sim.extractPeriodInfo(exp, ops)
                if periodlist != None:
                    maxid -= 1
                else:
                    periodlist = ['default']
                seqlist = self.sim.extractSequenceInfo(exp, ops)
                if seqlist != None:
                    maxid -= 1
                else:
                    seqlist = ['default']
                eventlist = self.sim.extractEventInfo(exp, ops)
                if eventlist != None:
                    maxid -= 1
                else:
                    eventlist = ['default']
                allrtvalues = {}
                allmpcsvalues = {}
                allsdvalues = {}
                allscostvalues = {}
                for n in nlist:
                    print 'Sensor Grid: %d x %d' % (n, n)
                    if micro:
                        allrtvalues[n] = {}
                        allmpcsvalues[n] = {}
                        allsdvalues[n] = {}
                        allscostvalues[n] = {}
                    for d in dlist:
                        # Setup commonly used filename variables
                        print 'Degree: ', d
                        if micro:
                            allrtvalues[n][d] = {}
                            allmpcsvalues[n][d] = {}
                            allsdvalues[n][d] = {}
                            allscostvalues[n][d] = {}
                        deployname = "/nodes" + str(n) + "degree" + str(d)
                        self.deploymentdir = self.sim.deployments + deployname
                        for l in losslist:
                            for ip in periodlist:
                                for seq in seqlist:
                                    for ev in eventlist:
                                        logdir = simdir + "/logs/"
                                        plotdir = simdir + "/plots/"
                                        for idx in range(1,maxid):
                                            logdir += ops[idx] + "/"
                                            plotdir += ops[idx] + "/"
                                        self.microdir = plotdir
                                        logdir += "alphaset" + ops[0] + deployname
                                        plotdir += "alphaset" + ops[0] + deployname
                                        self.microdir += "alphaset" + ops[0] + "/micro"
                                        lossrate = 0
                                        iperiod = 16
                                        seqnum = 0
                                        eventnum = 0
                                        if type(l)==type(1):
                                            if l > 0:
                                                logdir += "/loss" + str(l)
                                                plotdir += "/loss" + str(l)
                                                lossrate = l
                                        if type(ip)==type(1):
                                            if ip != 16:
                                                logdir += "/iter" + str(ip)
                                                plotdir += "/iter" + str(ip)
                                                iperiod = ip
                                        if type(seq)==type(1):
                                            if seq > 0:
                                                logdir += "/seq" + str(seq)
                                                plotdir += "/seq" + str(seq)
                                                seqnum = seq
                                        if type(ev)==type(1):
                                            if ev > 0:
                                                logdir += "/event" + str(ev)
                                                plotdir += "/event" + str(ev)
                                                eventnum = ev
                                        self._createDir(plotdir)
                                        rtlist = []
                                        mpcslist = []
                                        sdlist = []
                                        scostlist = []
                                        # Reset latencies from last batch of
                                        # runs
                                        self.latencies = []
                                        for r in runs:
                                            logname = logdir + "/run" + str(r) + ".txt"
                                            plotdir_r = plotdir + "/run" + str(r)
                                            self._createPlotRunDir(exp, plotdir_r)
                                            if macro:
                                                print 'Extracting MACRO results for run %d, loss %d, max iteration period %d...'%(r,lossrate,iperiod)
                                                nodes = lparser.Parse(logname)
                                                self.GroupActuatorEstimates(exp, nodes)
                                                self.GroupEvents(exp, nodes)
                                                self.GetOptimizers(r)
                                                self.GetInitialCost(r)
                                                #self.PlotEstimates(exp, plotdir_r)
                                                #self.PlotEstimateDistance(exp, ops, plotdir_r)
                                                self.PlotObjectiveFn(exp, ops,
                                                        nodes, r, plotdir_r, factor)
                                                self.SaveSchedule(exp, ops, nodes,
                                                        plotdir_r, 100)
                                                #self.PlotLocalCost(exp, r, plotdir_r)
                                                #self.PlotMessages(exp, ops, nodes, plotdir_r, r)
                                                #self.PlotSchedule(exp, ops, nodes, plotdir_r)
                                                self.act_est = {}
                                                nodes = {}
                                            if micro:
                                                print 'Extracting MICRO results for run %d, loss %d, max iteration period %d...'%(r,lossrate,iperiod)
                                                microlp.ParseFile(logname)
                                                (stats, tmsg) = microlp.GetStats()
                                                rtlist += [ mean(nstats['rt']) for nstats in
                                                        stats.itervalues() ]
                                                mpcslist += [ mean(nstats['mpcs']) for nstats in
                                                        stats.itervalues() ]
                                                sdlist += [ mean(nstats['syncdelay']) for nstats in
                                                        stats.itervalues() ]
                                                scostlist += [ nstats['synccost'] for nstats in
                                                        stats.itervalues() ]
                                                stats = {}
                                                tmsg = {}
                                        if macro:
                                            self.PlotMeanLatency(exp, ops, plotdir)
                                            self.PlotMeanCost(exp, ops, plotdir)
                                            self.PlotPerIterationMetrics(exp, ops, plotdir)
                                        if micro:
                                            # Get mean and std of RT for this (n,d)
                                            allrtvalues[n][d][lossrate] = (mean(rtlist), sd(rtlist))
                                            allmpcsvalues[n][d][lossrate] = (mean(mpcslist), sd(mpcslist))
                                            allsdvalues[n][d][lossrate] = (mean(sdlist), sd(sdlist))
                                            allscostvalues[n][d][lossrate] = (mean(scostlist), sd(scostlist))
                    print '================================================='
                    print 'Experiment: %s - Done for grid %d x %d'%(exp,n,n)
                    print '================================================='
                # All grid sizes processed.
                if micro:
                    self._createDir(self.microdir)
                    self.PlotvsDensity(exp, ops, allrtvalues, 
                            'rt_density.txt')
                    self.PlotvsDensity(exp, ops, allmpcsvalues,
                            'mpcs_density.txt')
                    self.PlotvsDensity(exp, ops, allsdvalues,
                            'sd_density.txt')
                    self.PlotvsDensity(exp, ops, allscostvalues,
                            'sync_cost_density.txt')

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

