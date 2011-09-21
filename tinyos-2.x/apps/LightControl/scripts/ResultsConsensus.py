#/usr/bin/python

import sys, os
import random
import getopt
import math
from multiprocessing import Process
import subprocess

from ParseLogFile import *
import scipy.io as sio
import numpy as np

import gc

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
        self.is_sync = True # Synchronized or Unsynchronized version
        self.act_est = {}   # Dictionary of actuator estimates
        self.min_start = 0  # Start offset of estimation process
        self.opt_est = []   # Optimal estimates
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
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
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
        self.latencies = []
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        for (n, objn) in nodes.iteritems():
            # n : sensor node
            # objn : instance of class Node
            for (id, estimates) in objn.estimates.iteritems():
                # id : actuator
                # estimates : list of estimates for actuator 'id' by sensor
                # 'n' where each element is e = {...}
                if id not in self.act_est:
                    self.act_est[id] = {}
                self.act_est[id][n] = estimates
        # Now find the min start time of the estimate procedure
        start_times = [ min([estimates[0]['time'] for estimates in
            nestimates.itervalues()]) for nestimates in self.act_est.itervalues() ]
        self.min_start = min(start_times)
        self.M = len(self.act_est)
        self.N = len(nodes)
        print 'Number of actuators:', self.M
        print 'Number of sensors:', self.N
        print 'Start time of estimation process:', self.min_start
        gc.collect()

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
        iterlist = [ min([len(elist) for elist in n_est.itervalues()]) for
                n_est in self.act_est.itervalues() ]
        return min(iterlist)

    def _getLocalEstimateI(self, exp, node, i):
        est_i = []
        for j in range(self.M):
            if node in self.act_est[j]:
                # 'node' estimated for actuator 'j'
                try:
                    est_i.append(self.act_est[j][node][i]['value'])
                except IndexError:
                    est_i.append(0)
            else:
                est_i.append(0)
        return est_i

    def PlotLocalCost(self, exp, r, plotdir):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        print' Plotting local cost at each node...'
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
                e = [ elist[i] for elist in
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
        elif exp in [ 'Cyclic' ]:
            # Only Node 0 estimates matter
            est_i = [ self.act_est[j][0][i]['value'] for j in range(self.M) ]
        return est_i

    def _getTime(self, exp, i, use_max=True):
        iterlist = [ 0 ]
        if exp in [ 'Consensus', 'FastCyclic', 'FastConsensus' ]:
            iterlist = [ min([elist[i]['time'] for elist in n_est.itervalues()])
                    for n_est in self.act_est.itervalues() ]
        elif exp in [ 'Cyclic' ]:
            # Any actuator, Node 0, i_th iteration
            iterlist = [ self.act_est[0][0][i]['time'] ]
        if use_max:
            return max(iterlist)
        else:
            return min(iterlist)

    def PlotEstimateDistance(self, exp, plotdir):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
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
            if exp in [ 'Cyclic' ]:
                # To account for message split cost
                delta = 4*delta
            plotstr = str(delta) + '\t'
            plotstr += str(i) + '\t'
            plotstr += str(val)
            plotf.write(plotstr + '\n')
        plotf.close()

    def PlotObjectiveFn(self, exp, r, plotdir):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        print' Plotting objective function...'
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
        for i in range(num_iter):
            # For each iteration i, plot the current value of objective fn
            est_i = self._getEstimateI(exp, i)
            I = np.reshape(est_i, [self.M, 1])
            f1 = np.dot(A,I).reshape([1, self.N])
            cost = f1 + Phi - L
            val = np.dot(cost, cost.T)[0,0]
            if i == (num_iter-1):
                print 'Estimate (%d): %s'%(i,str(est_i))
                print 'Cost vector:', cost
                print 'Value:', val
            t = self._getTime(exp, i)
            delta = t-self.min_start
            #if exp in [ 'Cyclic' ]:
            #    # To account for message split cost
            #    delta = 4*delta
            if not found:
                if val < 0.001:
                    e['time'] = delta
                    e['iter'] = i
                    found = True
            plotstr = str(delta) + '\t'
            plotstr += str(i) + '\t'
            plotstr += str(val)
            if exp in [ 'FastCyclic', 'Consensus', 'FastConsensus' ]:
                dmin = self._getTime(exp, i, False) - self.min_start
                plotstr += '\t' + str(dmin)
            plotf.write(plotstr + '\n')
        plotf.close()
        if e == {}:
            print 'Not found. Threshold 0.001 too low.'
        else:
            self.latencies.append(e)

    def PlotLatency(self, exp, nodes, plotdir, r):
        validlist = [ 'Central' ]
        if exp not in validlist:
            return
        print 'Plotting latency for run', r
        mode = 'a'
        if r == 0:
            mode = 'w'
        plotfile = plotdir + '/latency.dat'
        plotf = open(plotfile, mode)
        first_tx = min([ min([e['time'] for e in objn.tx]) if objn.tx!=[] else 10000000 for objn in
            nodes.itervalues() ])
        last_rx = max([e['time'] for e in nodes[0].rx])  # Node 0 is the base station
        elat = {}
        elat['time'] = last_rx - first_tx
        plotstr = str(r) + '\t' + str(elat['time'])
        self.latencies.append(elat)
        plotf.write(plotstr + '\n')
        plotf.close()

    def PlotMeanLatency(self, exp, plotdir):
        print 'Plotting mean latencies across all the runs.'
        plotfile = plotdir + '/mean_latency.dat'
        ltime = [ el['time'] for el in self.latencies ]
        liter = [ el['iter'] if 'iter' in el else 0 for el in self.latencies ]
        if ltime == []:
            print 'No latencies found.'
            return
        plotf = open(plotfile, 'w')
        mtime = mean(ltime)
        stdtime = sd(ltime)
        miter = mean(liter)
        stditer = sd(liter)
        plotstr = exp + '\t' + str(mtime) + '\t' + str(stdtime)
        plotstr += '\t' + str(miter) + '\t' + str(stditer)
        print 'Mean latency: Time %f %f'%(mtime,stdtime)
        print 'Mean latency: Iterations %f %f'%(miter,stditer)
        plotf.write(plotstr+'\n')
        plotf.close()

    def Generate(self, elist, nlist, dlist, clist, plist, runs):
        lparser = Parser(self.verbose)
        for exper in elist:
            self.is_sync = True
            exp = exper
            if exper.find('Unsync') > -1:
                # Unsynchronized version of experiment
                # Set flag and strip out 'Unsync'
                self.is_sync = False
                exp = exper.replace('Unsync', '')
            # Setup commonly used filename variables
            self.expdir = self.sim.rootdir + "/" + exp
            simdir = self.expdir + "/sim"
            print '======================'
            print 'Experiment: ', exp
            self.setPythonPath()
            for n in nlist:
                print 'Sensor Grid: %d x %d' % (n, n)
                for d in dlist:
                    # Setup commonly used filename variables
                    print 'Degree: ', d
                    deployname = "/nodes" + str(n) + "degree" + str(d)
                    self.deploymentdir = self.sim.deployments + deployname
                    for d_comm in clist:
                        for psi in plist:
                            logdir = simdir + "/logs/alphaset2" + deployname
                            plotdir = simdir + "/plots/alphaset2" + deployname
                            if not self.is_sync:
                                logdir += "/unsync"
                                plotdir += "/unsync"
                            logdir += '/comm' + str(d_comm)
                            logdir += '/psi' + str(psi)
                            plotdir += '/comm' + str(d_comm)
                            plotdir += '/psi' + str(psi)
                            self._createDir(plotdir)
                            for r in runs:
                                logname = logdir + "/run" + str(r) + ".txt"
                                plotdir_r = plotdir + "/run" + str(r)
                                self._createPlotRunDir(exp, plotdir_r)
                                print 'Extracting results...'
                                nodes = lparser.Parse(logname)
                                self.GroupActuatorEstimates(exp, nodes)
                                self.GetOptimizers(r)
                                self.PlotEstimates(exp, plotdir_r)
                                self.PlotEstimateDistance(exp, plotdir_r)
                                self.PlotObjectiveFn(exp, r, plotdir_r)
                                self.PlotLatency(exp, nodes, plotdir, r)
                                self.PlotLocalCost(exp, r, plotdir_r)

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

