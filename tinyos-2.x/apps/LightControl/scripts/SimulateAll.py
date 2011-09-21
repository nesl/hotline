

import sys, os
import random
import getopt
import math
from multiprocessing import Process
import subprocess

from Results import *

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

    def __createSoftLink(self, tfilestr, linkfilestr):
        target = self.deploymentdir + tfilestr
        link = self.expdir + linkfilestr
        pstr = "ln -sf " + target + " " + link
        print "Creating soft link to ", target
        p = subprocess.Popen(pstr, shell=True)
        p.wait()

    def _createSoftLink(self, filestr):
        self.__createSoftLink(filestr, filestr)

    def setAppName(self, exp, ops):
        if exp == 'FastCyclic':
            if 'static' in ops:
                self.appName = 'EstimatorStatic'
            elif 'dynamic' in ops:
                self.appName = 'EstimatorDynamic'
            else:
                self.appName = 'Estimator'
        else:
            self.appName = 'Estimator'

    def setNumNodes(self, exp, N, M):
        validlist = [ 'HierFastConsensus' ]
        if exp not in validlist:
            self.numNodes = N
        else:
            self.numNodes = N + M

    def linkDeploymentHdr(self, exp):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus', 'HierFastConsensus']
        if exp not in validlist:
            return
        filestr = "/deployment.h"
        self._createSoftLink(filestr)

    def linkSourceRoutes(self, exp, ops, seqnum=0):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus', 'HierFastConsensus']
        if exp not in validlist:
            return
        linkfile = "/routes.h"
        targetfile = linkfile
        if exp == 'Cyclic':
            if 'mhop' in ops:
                targetfile = "/ring_routes"
                if seqnum > 0:
                    targetfile += str(seqnum)
                targetfile += ".h"
            else:
                targetfile = "/ring_routes_ie"
                if seqnum > 0:
                    targetfile += str(seqnum)
                targetfile += ".h"
        self.__createSoftLink(targetfile, linkfile)
        # Now link the config header file
        linkfile = "/src_route_config.h"
        targetfile = linkfile
        if exp == 'Cyclic':
            if 'mhop' in ops:
                targetfile = "/src_route_config"
                if seqnum > 0:
                    targetfile += str(seqnum)
                targetfile += ".h"
            else:
                targetfile = "/src_route_config_ie"
                if seqnum > 0:
                    targetfile += str(seqnum)
                targetfile += ".h"
        self.__createSoftLink(targetfile, linkfile)

    def linkWeights(self, exp):
        validlist = [ 'Consensus' ]
        if exp not in validlist:
            return
        filestr = "/metweights.h"
        self._createSoftLink(filestr)

    def linkFastWeights(self, exp):
        validlist = [ 'FastConsensus' ]
        if exp not in validlist:
            return
        filestr = "/fastweights.h"
        self._createSoftLink(filestr)

    def linkZoneDep(self, exp):
        validlist = [ 'FastCyclic', 'FastConsensus' ]
        if exp not in validlist:
            return
        filestr = "/zonedep.h"
        self._createSoftLink(filestr)

    def linkSensorData(self, exp, r):
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus', 'HierFastConsensus']
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
        validlist = [ 'Cyclic', 'FastCyclic', 'Consensus', 'FastConsensus', 'HierFastConsensus']
        if exp not in validlist:
            return
        filestr = "/misc_params.h"
        self._createSoftLink(filestr)

    def linkTopology(self, exp, seqnum=0):
        validlist = [ 'Cyclic' ]
        if exp not in validlist:
            return
        linkfile = "/ring.h"
        targetfile = "/ring"
        if seqnum > 0:
            targetfile += str(seqnum)
        targetfile += ".h"
        self.__createSoftLink(targetfile, linkfile)
        #self._createSoftLink(filestr)
        #filestr = "/priority.h"
        #self._createSoftLink(filestr)

    def linkPriority(self, exp, seqnum=0):
        validlist = [ 'FastCyclic' ]
        if exp not in validlist:
            return
        tfile = "/priority"
        if seqnum > 0:
            tfile += str(seqnum)
        tfile += ".h"
        self.__createSoftLink(tfile, "/priority.h")

    def extractLossInfo(self, exp, ops):
        for op in ops:
            if type(op)==type([]):
                if 'loss' in op:
                    if len(op[1:]) > 0:
                        # Remove 'loss' from the list as some non-negative
                        # losses need to be simulated
                        return op[1:]
                    else:
                        # Only 'loss' is in the list
                        return op
        return None

    def extractPeriodInfo(self, exp, ops):
        for op in ops:
            if type(op)==type([]):
                if 'iter' in op:
                    if len(op[1:]) > 0:
                        # Remove 'iter' from the list.
                        return op[1:]
                    else:
                        # Only 'iter' is in the list
                        return op
        return None

    def extractSequenceInfo(self, exp, ops):
        for op in ops:
            if type(op)==type([]):
                if 'seq' in op:
                    if len(op[1:]) > 0:
                        # Remove 'seq' from the list.
                        return op[1:]
                    else:
                        # Only 'seq' is in the list
                        return op
        return None

    def extractEventInfo(self, exp, ops):
        for op in ops:
            if type(op)==type([]):
                if 'event' in op:
                    if len(op[1:]) > 0:
                        # Remove 'event' from the list.
                        return op[1:]
                    else:
                        # Only 'event' is in the list
                        return op
        return None

    def createStepHdr(self, exp, ops, slist, lossrate, degree, iperiod, ev):
        filename = self.expdir + '/step.h'
        stepf = open(filename, 'w')
        stepf.write('#ifndef _STEP_H_\n')
        stepf.write('#define _STEP_H_\n\n')
        if 'static' in ops:
            stepf.write('#define STATIC_PR\n')
            stepf.write('#define MAXIMUM_ITER_PERIOD\t'+str(iperiod)+'\n')
        if 'adaptive' in ops:
            stepf.write('#define ADAPTIVE\n')
        if ev > 0:
            stepf.write('#define SIM_EVENTS\n')
        if 'ring' in ops:
            stepf.write('#define RING_PR\n')
        if 'timestamps' in ops:
            stepf.write('#define TIMESTAMPS\n')
        if 'relax' in ops:
            stepf.write('#define PHYLOCK_RELAX_ACCESS\n')
        if 'mhop' not in ops:
            stepf.write('#define USE_BROADCAST\n')
        if 'unsync' in ops:
            stepf.write('#define UNSYNC\n')
        idx = int(ops[0])-1
        if (exp=='Consensus') and (idx>0):
            idx += 1
        step = slist[idx][degree]
        stepf.write('#define STEP_SIZE\t'+str(step)+'\n\n')
        if lossrate > 0:
            pstr = '#ifdef PACKET_LOSS_RATE\n#undef PACKET_LOSS_RATE\n#endif'
            stepf.write(pstr+'\n')
            stepf.write('#define PACKET_LOSS_RATE\t'+str(lossrate)+'\n\n')
        stepf.write('#endif\n')
        stepf.close()

    def processWireConfig(self, exp):
        M = 0
        inFilename = self.deploymentdir + "/wireconfig.txt"
        inFile = open(inFilename, 'r')
        for newl in inFile:
            newfields = newl.split(':')
            if 'REP' in newfields:
                # Count number of actuators
                M += 1
        inFile.close()
        return M

    def getIterationCount(self, exp, ops, n, d):
        if exp == 'Cyclic':
            return 200
        elif exp == 'FastCyclic':
            if 'adaptive' in ops:
                eventlist = self.extractEventInfo(exp, ops)
                if eventlist == None:
                    if 'static' in ops:
                        return 400
                    return 200
            #if 'static' in ops:
            #    seqlist = self.extractSequenceInfo(exp, ops)
            #    if seqlist != None:
            #        return 400
            #    if 'nodeid' in ops:
            #        return 400
        return 100

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

    def Run(self, elist, nlist, dlist, slist, runs):
        for (exp, oplist) in elist.iteritems():
            for ops in oplist:
                # Setup commonly used filename variables
                self.expdir = self.rootdir + "/" + exp
                simdir = self.expdir + "/sim"
                print '======================'
                print 'Experiment: ', exp
                print 'Options -- ', ops
                self.setPythonPath()
                maxid = len(ops)
                losslist = self.extractLossInfo(exp, ops)
                if losslist != None:
                    maxid -= 1
                else:
                    losslist = ['default']
                periodlist = self.extractPeriodInfo(exp, ops)
                if periodlist != None:
                    maxid -= 1
                else:
                    periodlist = ['default']
                seqlist = self.extractSequenceInfo(exp, ops)
                if seqlist != None:
                    maxid -= 1
                else:
                    seqlist = ['default']
                eventlist = self.extractEventInfo(exp, ops)
                if eventlist != None:
                    maxid -= 1
                else:
                    eventlist = ['default']
                for n in nlist:
                    print 'Sensor Grid: %d x %d' % (n, n)
                    for d in dlist:
                        # Setup commonly used filename variables
                        print 'Degree: ', d
                        deployname = "/nodes" + str(n) + "degree" + str(d)
                        self.deploymentdir = self.deployments + deployname
                        for l in losslist:
                            for ip in periodlist:
                                for seq in seqlist:
                                    for ev in eventlist:
                                        logdir = simdir + "/logs/"
                                        for idx in range(1,maxid):
                                            logdir += ops[idx] + "/"
                                        logdir += "alphaset" + ops[0] + deployname
                                        lossrate = 0
                                        iperiod = 16
                                        seqnum = 0
                                        eventnum = 0
                                        if type(l)==type(1):
                                            if l > 0:
                                                logdir += "/loss" + str(l)
                                                lossrate = l
                                        if type(ip)==type(1):
                                            if ip != 16:
                                                logdir += "/iter" + str(ip)
                                                iperiod = ip
                                        if type(seq)==type(1):
                                            if seq > 0:
                                                logdir += "/seq" + str(seq)
                                                seqnum = seq
                                        if type(ev)==type(1):
                                            if ev > 0:
                                                logdir += "/event" + str(ev)
                                                eventnum = ev
                                        topofilename = self.deploymentdir + "/"
                                        if exp == 'HierFastConsensus':
                                            topofilename += "hier"
                                        topofilename += "topology.txt"
                                        if 'mhop' in ops:
                                            # Use the D1 topology file instead
                                            topobase = self.deployments + "/nodes" + str(n) + "degree1/"
                                            topofilename = topobase + "topology.txt"
                                        # Create logs directory
                                        print 'Creating log directory: ', logdir
                                        pstr = "mkdir -p " + logdir
                                        p = subprocess.Popen(pstr, shell=True)
                                        p.wait()
                                        # Create soft links to necessary files
                                        self.setAppName(exp, ops)
                                        self.linkDeploymentHdr(exp)
                                        self.linkSourceRoutes(exp, ops, seqnum)
                                        self.linkWeights(exp)
                                        self.linkFastWeights(exp)
                                        self.linkZoneDep(exp)
                                        self.linkTopology(exp, seqnum)
                                        self.linkPriority(exp, seqnum)
                                        M = self.processWireConfig(exp)
                                        print 'Number of actuators:', M
                                        self.linkMiscParams(exp)
                                        self.createStepHdr(exp, ops, slist, lossrate,
                                                d, iperiod, eventnum)
                                        self.setNumNodes(exp, n*n, M)
                                        itercount = self.getIterationCount(exp, ops, n, d)
                                        for r in runs:
                                            self.linkSensorData(exp, r)
                                            self.compileApp(exp)
                                            print 'Starting simulation...'
                                            logname = logdir + "/run" + str(r) + ".txt"
                                            args = "python TestSimEvents.py -n " + str(self.numNodes)
                                            args += " -a " + self.appName + "P -t " + topofilename
                                            args += " -l " + logname + " -x " + self.expdir
                                            args += " -e " + str(eventnum) + " -i " + str(itercount)
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
    ###########################################
    ###########################################
    # Set type of simulations that need to be run
    elist = {}
    ###########################################
    elist['Cyclic'] = [['1']]
    #elist['Cyclic'][0] += ['mhop']
    elist['Cyclic'][0] += [ ['seq', 4, 5, 6] ]
    ###########################################
    #elist['Cyclic'] += [['1']]
    #elist['Cyclic'][1] += ['mhop']
    #elist['FastCyclic'][1] += [ ['seq', 1, 2, 3, 4, 5] ]
    ###########################################
    #elist['Consensus'] = [['2']]
    #elist['Consensus'][0] += ['unsync']
    ###########################################
    #elist['Central'] = [['1']]
    ###########################################
    #elist['FastConsensus'] = [['2']]
    #elist['FastConsensus'][0] += ['mhop']
    #elist['FastConsensus'][0] += ['unsync']
    ###########################################
    #elist['HierFastConsensus'] = [['2']]
    ###########################################
    #elist['FastCyclic'] = [['1']]
    #elist['FastCyclic'][0] += [ 'unsync' ]
    #elist['FastCyclic'][0] += [ 'static' ]
    #elist['FastCyclic'][0] += [ 'dynamic' ]
    #elist['FastCyclic'][0] += [ 'WC' ]
    #elist['FastCyclic'][0] += [ 'adaptive' ]
    #elist['FastCyclic'][0] += [ 'ring' ]
    #elist['FastCyclic'][0] += [ 'nodeid' ]
    #elist['FastCyclic'][0] += [ 'timestamps' ]
    #elist['FastCyclic'][0] += [ 'relax' ]
    #elist['FastCyclic'][0] += [ 'mhop' ]
    #elist['FastCyclic'][0] += [ ['loss',] ]
    #elist['FastCyclic'][0] += [ ['iter', 16, 32, 64] ]
    #elist['FastCyclic'][0] += [ ['seq', 1, 2, 3, 4, 5] ]
    #elist['FastCyclic'][0] += [ ['event', 1, 5, 10, 25] ]
    ###########################################
    #elist['FastCyclic'] += [['1']]
    #elist['FastCyclic'][1] += [ 'unsync' ]
    #elist['FastCyclic'][1] += [ 'static' ]
    #elist['FastCyclic'][1] += [ 'dynamic' ]
    #elist['FastCyclic'][1] += [ 'WC' ]
    #elist['FastCyclic'][1] += [ 'adaptive' ]
    #elist['FastCyclic'][1] += [ 'ring' ]
    #elist['FastCyclic'][1] += [ 'nodeid' ]
    #elist['FastCyclic'][1] += [ 'timestamps' ]
    #elist['FastCyclic'][1] += [ 'relax' ]
    #elist['FastCyclic'][1] += [ 'mhop' ]
    #elist['FastCyclic'][1] += [ ['loss',] ]
    #elist['FastCyclic'][1] += [ ['iter', 32, 64] ]
    #elist['FastCyclic'][1] += [ ['seq',] ]
    #elist['FastCyclic'][1] += [ ['event', 1, 5, 10, 25] ]
    ###########################################
    #elist['FastCyclic'] += [['1']]
    #elist['FastCyclic'][2] += [ 'unsync' ]
    #elist['FastCyclic'][2] += [ 'static' ]
    #elist['FastCyclic'][2] += [ 'dynamic' ]
    #elist['FastCyclic'][2] += [ 'WC' ]
    #elist['FastCyclic'][2] += [ 'adaptive' ]
    #elist['FastCyclic'][2] += [ 'ring' ]
    #elist['FastCyclic'][2] += [ 'nodeid' ]
    #elist['FastCyclic'][2] += [ 'timestamps' ]
    #elist['FastCyclic'][2] += [ 'relax' ]
    #elist['FastCyclic'][2] += [ 'mhop' ]
    #elist['FastCyclic'][2] += [ ['loss',] ]
    #elist['FastCyclic'][2] += [ ['iter',] ]
    #elist['FastCyclic'][2] += [ ['seq',] ]
    #elist['FastCyclic'][2] += [ ['event', 1, 5, 10, 25] ]
    ###########################################
    #elist['FastCyclic'] += [['1']]
    #elist['FastCyclic'][3] += [ 'unsync' ]
    #elist['FastCyclic'][3] += [ 'static' ]
    #elist['FastCyclic'][3] += [ 'dynamic' ]
    #elist['FastCyclic'][3] += [ 'WC' ]
    #elist['FastCyclic'][3] += [ 'adaptive' ]
    #elist['FastCyclic'][3] += [ 'ring' ]
    #elist['FastCyclic'][3] += [ 'nodeid' ]
    #elist['FastCyclic'][3] += [ 'timestamps' ]
    #elist['FastCyclic'][3] += [ 'relax' ]
    #elist['FastCyclic'][3] += [ 'mhop' ]
    #elist['FastCyclic'][3] += [ ['loss',] ]
    #elist['FastCyclic'][3] += [ ['iter',] ]
    #elist['FastCyclic'][3] += [ ['seq',] ]
    #elist['FastCyclic'][3] += [ ['event', 1] ]
    ###########################################
    #elist['FastCyclic'] += [['1']]
    #elist['FastCyclic'][4] += [ 'unsync' ]
    #elist['FastCyclic'][4] += [ 'static' ]
    #elist['FastCyclic'][4] += [ 'dynamic' ]
    #elist['FastCyclic'][4] += [ 'WC' ]
    #elist['FastCyclic'][4] += [ 'adaptive' ]
    #elist['FastCyclic'][4] += [ 'ring' ]
    #elist['FastCyclic'][4] += [ 'nodeid' ]
    #elist['FastCyclic'][4] += [ 'timestamps' ]
    #elist['FastCyclic'][4] += [ 'relax' ]
    #elist['FastCyclic'][4] += [ 'mhop' ]
    #elist['FastCyclic'][4] += [ ['loss',] ]
    #elist['FastCyclic'][4] += [ ['iter',] ]
    #elist['FastCyclic'][4] += [ ['seq',] ]
    #elist['FastCyclic'][4] += [ ['event', 1] ]
    ###########################################
    #elist['FastCyclic'] += [['1']]
    #elist['FastCyclic'][5] += [ 'unsync' ]
    #elist['FastCyclic'][5] += [ 'static' ]
    #elist['FastCyclic'][5] += [ 'dynamic' ]
    #elist['FastCyclic'][5] += [ 'WC' ]
    #elist['FastCyclic'][5] += [ 'adaptive' ]
    #elist['FastCyclic'][5] += [ 'ring' ]
    #elist['FastCyclic'][5] += [ 'nodeid' ]
    #elist['FastCyclic'][5] += [ 'timestamps' ]
    #elist['FastCyclic'][5] += [ 'relax' ]
    #elist['FastCyclic'][5] += [ 'mhop' ]
    #elist['FastCyclic'][5] += [ ['loss',] ]
    #elist['FastCyclic'][5] += [ ['iter',] ]
    #elist['FastCyclic'][5] += [ ['seq',] ]
    #elist['FastCyclic'][5] += [ ['event', 1] ]
    ###########################################
    #elist['FastCyclic'] += [['1']]
    #elist['FastCyclic'][6] += [ 'unsync' ]
    #elist['FastCyclic'][6] += [ 'static' ]
    #elist['FastCyclic'][6] += [ 'dynamic' ]
    #elist['FastCyclic'][6] += [ 'WC' ]
    #elist['FastCyclic'][6] += [ 'adaptive' ]
    #elist['FastCyclic'][6] += [ 'ring' ]
    #elist['FastCyclic'][6] += [ 'nodeid' ]
    #elist['FastCyclic'][6] += [ 'timestamps' ]
    #elist['FastCyclic'][6] += [ 'relax' ]
    #elist['FastCyclic'][6] += [ 'mhop' ]
    #elist['FastCyclic'][6] += [ ['loss',] ]
    #elist['FastCyclic'][6] += [ ['iter',] ]
    #elist['FastCyclic'][6] += [ ['seq',] ]
    #elist['FastCyclic'][6] += [ ['event', 1] ]
    ###########################################
    ###########################################
    # Step sizes for New setups
    # Step Set 1 - For all
    slist = [{ 1:10, 2:20, 3:5, 4:2 }]
    # Step Set 2 - For Fast/Hier Consensus
    slist += [{ 1:10*4, 2:20*1, 3:5*2, 4:2*4 }]
    # Step Set 2 - For 'Consensus' only
    slist += [{ 1:10*8, 2:20*3, 3:5*4, 4:2*8 }]
    # Step sizes for old setups
    #slist = { 1:10, 2:400, 3:200, 4:200 }
    ###########################################
    #nlist = [ 3, 5, 7, 10 ]
    nlist = [ 7 ]
    dlist = [ 1, 2, 3 ]
    #dlist = [ 1, 2, 3 ]
    #runs = [ 0 ]
    runs = range(10)
    factor = 0.0001
    ###########################################
    s.Run(elist, nlist, dlist, slist, runs)
    r.Generate(elist, nlist, dlist, runs, factor)
    #r.Generate(elist, nlist, dlist, runs, factor, False, True)

