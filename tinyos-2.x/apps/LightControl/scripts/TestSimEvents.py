
import sys
import random
import getopt
from TOSSIM import *
from tinyos.tossim.TossimApp import *
from UserEventMsg import *
from k_subset import *

def doOneSimulation(numNodes, appName, topofilename, logfilename, xmldir,
        gain, events, itercount): 
    # Initialize TOSSIM
    xmlfile = xmldir + "/app.xml"
    n = NescApp("Unknown App", xmlfile)
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
    t.addChannel(appName + "Eval", logfile)
    t.addChannel("SynchronizePEval", logfile)
    t.addChannel("VirtualLockPEval", logfile)
    t.addChannel("TransportPEval", logfile)
    t.addChannel("RoutePEval", logfile)
    t.addChannel("NeighborPEval", logfile)
    t.addChannel("ShareDataPEval", logfile)
    # Extra debugging
    #t.addChannel(appName, logfile)
    #t.addChannel("StatsPEval", logfile)
    #t.addChannel("SynchronizeP", logfile)
    #t.addChannel("DummySensorP", logfile)
    #t.addChannel("SharedMemoryPEval", logfile)
    #t.addChannel("CachePEval", logfile)
    # Boot all the nodes
    for i in range(numNodes):
        t.getNode(i).bootAtTime(4 * t.ticksPerSecond() + 242119)
        #t.getNode(i).bootAtTime(random.randint(0,23512178) + 23542399)
    # Setup simulation done checks
    var_list_confirm = {}
    for i in range(numNodes):
        var_list_confirm[i] = {}
        var_list_confirm[i]['done'] = t.getNode(i).getVariable(appName + ".done")
        var_list_confirm[i]['iters'] = t.getNode(i).getVariable(appName + ".finish_iter")
    do_break = False
    # Simulate till all nodes are done with phase 1
    while (not do_break):
        # While all nodes haven't signalled 'done' and haven't finished their
        # iterations, stay in the loop.
        t.runNextEvent()
        do_break = True
        for (nid,checkvars) in var_list_confirm.iteritems():
            if ((checkvars['done'].getData()==0) and (checkvars['iters'].getData()<itercount)):
                do_break = False
                break
    if events > 0:
        # Some events need to be simulated
        # Select nodes to receive events
        pkts = []
        nodes = ranksb1(numNodes, events)
        for i in range(events):
            msg = UserEventMsg()
            msg.set_value(0);
            pkt = t.newPacket();
            pkt.setData(msg.data)
            pkt.setType(msg.get_amType())
            pkt.setDestination(nodes[i])
            pkts.append(pkt)
        for i in range(events):
            pkts[i].deliver(nodes[i], t.time() + t.ticksPerSecond())
            print 'Event detected at node', nodes[i]
        # Just wait for packet deliveries and allow time for nodes to reset
        # their 'done' status
        waittime = t.time() + (2*t.ticksPerSecond())
        while(t.time() < waittime):
            t.runNextEvent()
        # Wait over. Now simulate till nodes signal 'done' again.
        do_break = False
        while (not do_break):
            # While all nodes haven't signalled 'done' and haven't finished their
            # iterations, stay in the loop.
            t.runNextEvent()
            do_break = True
            for checkvars in var_list_confirm.itervalues():
                if ((checkvars['done'].getData()==0) and (checkvars['iters'].getData()<2*itercount)):
                    do_break = False
                    break
    if logfilename != None:
        logfile.close()

if (__name__ == '__main__'):
    try:
        longopts = ["verbose", "app=", "num=", "topo=", "log=", "xml=",
                "gain=", "events=", "iter="]
        opts, args = getopt.getopt(sys.argv[1:], "va:n:t:l:x:g:e:i:", longopts)
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    topofilename = "topology.txt"
    logfilename = None
    appName = "EasyCollectionC"
    numNodes = 9
    xmldir = "."
    gain = None
    events = 0
    itercount = 10
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
        elif o in ("-x", "--xml"):
            xmldir = a
        elif o in ("-g", "--gain"):
            gain = int(a)
        elif o in ("-e", "--events"):
            events = int(a)
        elif o in ("-i", "--iter"):
            itercount = int(a)
    doOneSimulation(numNodes, appName, topofilename, logfilename, xmldir,
            gain, events, itercount)
