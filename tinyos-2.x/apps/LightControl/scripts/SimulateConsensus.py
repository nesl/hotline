#/usr/bin/python

import sys, os
import random
import getopt
import math
from multiprocessing import Process
import subprocess

from ResultsConsensus import *

class Simulation:
    def __init__(self, app='Estimator', verbose=False):
        self.verbose = verbose
        self.rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
        self.deployments = self.rootdir + "/DeploymentsNew"
        self.appName = app
        self.origPythonPath = os.getenv('PYTHONPATH')
        # These variables are set later
        self.numNodes = 0
        self.deploymentdir = ""
        self.expdir = ""
        self.is_sync = True # Synchronized or Unsynchronized version

    def _createSoftLink(self, filestr):
        target = self.deploymentdir + filestr
        link = self.expdir + filestr
        pstr = "ln -sf " + target + " " + link
        print "Creating soft link to ", target
        p = subprocess.Popen(pstr, shell=True)
        p.wait()

    def setNumNodes(self, exp, N, M):
        #validlist = [ 'FastCyclic' ]
        validlist = [ 'dummy' ]
        if exp not in validlist:
            self.numNodes = N
        else:
            self.numNodes = N + M

    def linkDeploymentHdr(self, exp):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        filestr = "/deployment.h"
        self._createSoftLink(filestr)

    def linkWeights(self, exp, n, d_comm):
        validlist = [ 'Consensus' ]
        if exp not in validlist:
            return
        filestr = '/metweights_'+str(n)+'_d'+str(d_comm)+'.h'
        target = self.rootdir + '/topology/comm' + filestr
        link = self.expdir + '/metweights.h'
        pstr = "ln -sf " + target + " " + link
        print "Creating soft link to ", target
        p = subprocess.Popen(pstr, shell=True)
        p.wait()

    def linkSensorData(self, exp, r):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        filestr = "/run" + str(r) + "/sensor.h"
        target = self.deploymentdir + filestr
        link = self.rootdir + "/Sensor/sensor.h"
        pstr = "ln -sf " + target + " " + link
        print "Creating soft link to ", target
        p = subprocess.Popen(pstr, shell=True)
        p.wait()

    def linkMiscParams(self, exp):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus' ]
        if exp not in validlist:
            return
        filestr = "/misc_params.h"
        self._createSoftLink(filestr)

    def createStepHdr(self, exp, step, psi):
        filename = self.expdir + '/step.h'
        stepf = open(filename, 'w')
        stepf.write('#ifndef _STEP_H_\n')
        stepf.write('#define _STEP_H_\n\n')
        stepf.write('#define STEP_SIZE\t'+str(step)+'\n')
        stepf.write('#define PSI\t'+str(psi)+'\n\n')
        stepf.write('#endif\n')
        stepf.close()

    def compileApp(self, exp):
        pstr = "cd " + self.expdir + "; make clean; make micaz sim"
        print "Compiling the application..."
        p = subprocess.Popen(pstr, shell=True)
        p.communicate()

    def setPythonPath(self):
        newPath = self.origPythonPath + self.expdir + ':'
        print 'Setting PYTHONPATH to ', newPath
        os.environ['PYTHONPATH'] = newPath

    def resetPythonPath(self):
        print 'Resetting PYTHONPATH.'
        os.environ['PYTHONPATH'] = self.origPythonPath

    def Run(self, elist, nlist, dlist, clist, plist, slist, runs):
        for exper in elist:
            self.is_sync = True
            exp = exper
            if exper.find('Unsync') > -1:
                # Unsynchronized version of experiment
                # Set flag and strip out 'Unsync'
                self.is_sync = False
                exp = exper.replace('Unsync', '')
                print 'Unsynchronized version:', exp
            # Setup commonly used filename variables
            self.expdir = self.rootdir + "/" + exp
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
                    topobase = self.rootdir+'/topology/comm/topo_'+str(n)+'_d'
                    self.deploymentdir = self.deployments + deployname
                    # Create soft links to necessary files
                    self.linkDeploymentHdr(exp)
                    self.linkMiscParams(exp)
                    self.setNumNodes(exp, n*n, 0)
                    for d_comm in clist:
                        topofilename = topobase + str(d_comm) + '.txt'
                        self.linkWeights(exp, n, d_comm)
                        for psi in plist:
                            # Create logs directory
                            logdir = simdir + "/logs/alphaset2" + deployname
                            if not self.is_sync:
                                logdir += "/unsync"
                            logdir += '/comm' + str(d_comm)
                            logdir += '/psi' + str(psi)
                            print 'Creating log directory: ', logdir
                            pstr = "mkdir -p " + logdir
                            p = subprocess.Popen(pstr, shell=True)
                            p.wait()
                            self.createStepHdr(exp, slist[d], psi)
                            for r in runs:
                                self.linkSensorData(exp, r)
                                self.compileApp(exp)
                                print "Starting simulation for [d_comm, PSI]: %d, %d"%(d_comm,psi)
                                logname = logdir + "/run" + str(r) + ".txt"
                                args = "python TestSim.py -n " + str(self.numNodes)
                                args += " -a " + self.appName + "P -t " + topofilename
                                args += " -l " + logname + " -x " + self.expdir
                                print "Cmd: ", args
                                p = subprocess.Popen(args, shell=True)
                                p.communicate()
                                print 'Simulation finished.'
        # After all simulations are done, reset the chages to OS environment
        self.resetPythonPath()


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
    s = Simulation('Estimator', verbose)
    r = Results(s, verbose)
    # Step sizes for New setups
    # Step size for Consensus
    slist = { 1:10*8, 2:20*3, 3:5*4, 4:2*8 }
    # Step size for FastConsensus
    #slist = { 1:10*4, 2:20*1, 3:5*2, 4:2*4 }
    # Step size for Cyclic
    #slist = { 1:10, 2:20, 3:5, 4:2 }
    elist = []
    #elist += [ 'Cyclic' ]
    elist += [ 'Consensus' ]
    #elist += [ 'UnsyncConsensus' ]
    #elist += [ 'Central' ]
    #elist += [ 'FastConsensus' ]
    #elist += [ 'FastCyclic' ]
    #elist += [ 'UnsyncFastConsensus' ]
    nlist = [ 7 ]
    dlist = [ 2 ]
    comm_list = [ 0, 4 ]
    #comm_list = [ 0, 1, 3, 4 ]
    psi_list = [ 10 ]
    #psi_list = [ 1, 10 ]
    ######## SELECT RUNS FROM OTHER CONSENSUS SIMULATIONS ####
    #runs = [ 2 ]
    runs = range(3)
    ######## SELECT RUNS FROM OTHER CONSENSUS SIMULATIONS ####
    s.Run(elist, nlist, dlist, comm_list, psi_list, slist, runs)
    r.Generate(elist, nlist, dlist, comm_list, psi_list, runs)

