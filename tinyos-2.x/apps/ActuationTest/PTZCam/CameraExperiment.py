#/usr/bin/python

import sys
import random
import getopt
import math
import ParseFile as parser
import subprocess

NUM_EXPERIMENTS = 10
NUM_NODES = 25
NUM_RUNS = 10

class Simulation:
    def __init__(self, appName, numNodes, verbose=False):
        self.verbose = verbose
        self.appName = appName
        self.numNodes = numNodes
        print "Creating simulation environment for ", self.appName
        print "Number of nodes: ", self.numNodes

    def Run(self, experiments, runs, loss=0, gain=None):
        simdir = "$TOSROOT/apps/ActuationTest/PTZCam/sim"
        gainstr = ""
        if gain != None:
            gainstr = str(gain)
        # Create logs directory
        logdir = "logs/camera" + gainstr + "/loss" + str(loss)
        pstr = "mkdir -p " + logdir
        print "Creating log directory..."
        p = subprocess.Popen(pstr, shell=True)
        p.wait()
        # Create plots directory
        plotdir = "plots/camera" + gainstr + "/loss" + str(loss)
        pstr = "mkdir -p " + plotdir
        print "Creating plots directory..."
        p = subprocess.Popen(pstr, shell=True)
        p.wait()
        # Create the range file
        print "Creating Range.h file..."
        rangefile = open('../Range.h', 'w')
        pstr = '#ifdef PACKET_LOSS_RATE\n#undef PACKET_LOSS_RATE\n#endif'
        rangefile.write(pstr+'\n\n')
        pstr = '#define PACKET_LOSS_RATE ' + str(loss)
        rangefile.write(pstr+'\n\n')
        rangefile.close()
        for i in experiments:
            print "====================\nEXPERIMENT #", i
            # Create soft links to pose file
            target = simdir + "/topology/camera_pose_" + str(i) + ".h"
            link = "$TOSDIR/lib/actuator/gen_pose.h"
            pstr = "ln -sf " + target + " " + link
            print "Creating soft link to pose file..."
            p = subprocess.Popen(pstr, shell=True)
            p.wait()
            # Compile the app
            pstr = "cd ..; make clean; make micaz sim"
            print "Compiling the application..."
            p = subprocess.Popen(pstr, shell=True)
            p.communicate()
            # Run the simulation
            topofile = "topology/camera_topo_" + str(i) + ".txt"
            logbase = logdir + "/log_pose_" + str(i) + "_"
            for r in range(runs):
                logfilename = logbase + str(r) + ".txt"
                print "Simulating run ", r, " log: ", logfilename
                args = "python ../CameraSim.py -n " + str(self.numNodes)
                args += " -a " + self.appName + " -t " + topofile
                args += " -l " + logfilename
                if gain != None:
                    args += " -g " + gainstr
                print "Cmd: ", args
                p = subprocess.Popen(args, shell=True)
                p.communicate()

if (__name__ == '__main__'):
    try:
        opts, args = getopt.getopt(sys.argv[1:], "ve", ["verbose", "errors"])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    list_errors = False
    gain = None
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-e", "--errors"):
            list_errors = True
    sim = Simulation("PtzCameraAppP", NUM_NODES, verbose)
    sim.Run(range(NUM_EXPERIMENTS), NUM_RUNS, 0)
    sim.Run(range(NUM_EXPERIMENTS), NUM_RUNS, 20)
    sim.Run(range(NUM_EXPERIMENTS), NUM_RUNS, 40)
    sim.Run(range(NUM_EXPERIMENTS), NUM_RUNS, 60)
    sim.Run(range(NUM_EXPERIMENTS), NUM_RUNS, 80)
