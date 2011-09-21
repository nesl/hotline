
import sys
import random
import getopt
from TOSSIM import *
from tinyos.tossim.TossimApp import *

def doOneSimulation(numNodes, appName, topofilename, logfilename, gain=None): 
    # Initialize TOSSIM
    n = NescApp("Unknown App", "../app.xml")
    t = Tossim(n.variables.variables())
    r = t.radio()
    # Initialize network topology
    f = open(topofilename, 'r')
    lines = f.readlines()
    for line in lines:
        s = line.split()
        if (len(s) > 0):
            if gain == None:
                r.add(int(s[0]), int(s[1]), float(s[2]))
            else:
                r.add(int(s[0]), int(s[1]), float(-gain))
    f.close()
    # Setup noise floor for radio communication
    for i in range(numNodes):
        m = t.getNode(i)
        for j in range (0, 100):
            m.addNoiseTraceReading(-105)
        m.createNoiseModel()
    # Listen to log channels
    if logfilename == None:
        logfile = sys.stdout
    else:
        logfile = open(logfilename, 'w')
    #t.addChannel("TestP1", logfile)
    #t.addChannel("VirtualLockP", logfile)
    t.addChannel("TestP1Eval", logfile)
    t.addChannel("VirtualLockPEval", logfile)
    t.addChannel("NeighborPEval", logfile)
    t.addChannel("TransportPEval", logfile)
    # Boot all the nodes
    for i in range(numNodes):
        t.getNode(i).bootAtTime(4 * t.ticksPerSecond() + 242119)
        #t.getNode(i).bootAtTime(random.randint(0,23512178) + 23542399)
    # Setup simulation done checks
    var_list_confirm = []
    for i in range(numNodes):
        var_list_confirm.append(t.getNode(i).getVariable(appName + ".done"))
    testsum = 0
    # Simulate till all nodes are done
    while(testsum < numNodes):
        testsum = 0
        t.runNextEvent()
        for n in var_list_confirm:
            testsum = testsum + n.getData()
    logfile.close()

if (__name__ == '__main__'):
    try:
        longopts = ["verbose", "app=", "num=", "topo=", "log=", "gain="]
        opts, args = getopt.getopt(sys.argv[1:], "va:n:t:l:g:", longopts)
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    topofilename = "topology/topo_3_d0.txt"
    logfilename = None
    appName = "TestP1"
    numNodes = 9
    gain = None
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-a", "--app"):
            appName = a
        elif o in ("-n", "--num"):
            numNodes = int(a)
        elif o in ("-t", "--topo"):
            topofilename = a
        elif o in ("-l", "--log"):
            logfilename = a
        elif o in ("-g", "--gain"):
            gain = int(a)
    doOneSimulation(numNodes, appName, topofilename, logfilename, gain)