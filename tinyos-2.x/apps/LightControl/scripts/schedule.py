import csv
import sys
import os
import getopt
import time

import networkx as nx
import scipy.io as sio
import numpy as np

from create_ring import *
from greedycolor import *

def makeGraph(filename, numNodes=None):
    fin = open(filename)
    reader = csv.reader(fin, delimiter=' ')
    G = nx.Graph()
    for row in reader:
        if numNodes != None:
            if (int(row[0])>=numNodes) or (int(row[1])>=numNodes):
                # Ignore nodes with id's greater than the limit
                continue
        G.add_edge(int(row[0]), int(row[1]))
    fin.close()
    return G

def set_priorities(dep_graph, seq):
    i = 0
    for n in seq:
        dep_graph.node[n]['pr'] = i
        dep_graph.node[n]['iteration'] = 0
        i += 1

def find_count(dep_graph, count):
    for n in dep_graph.nodes_iter():
        if dep_graph.node[n]['iteration'] == count:
            return True
    return False

def finished(dep_graph, count):
    for n in dep_graph.nodes_iter():
        if dep_graph.node[n]['iteration'] < count:
            return False
    return True

def can_schedule(dep_graph, n, max_iter):
    if dep_graph.node[n]['iteration'] >= max_iter:
        return False
    for neighbor in dep_graph.neighbors(n):
        i = dep_graph.node[n]['iteration']
        if dep_graph.node[neighbor]['pr'] < dep_graph.node[n]['pr']:
            # This is a higher priority neighbor. 
            if (dep_graph.node[neighbor]['iteration']<=i):
                # It hasn't finished its (i+1)^{th} iteration yet.
                return False
        else:
            # This is a lower priority neighbor
            if (dep_graph.node[neighbor]['iteration']<i):
                # It hasn't finished its i^(th) iteration yet.
                return False
    return True

def get_schedule(dep_graph, seq, N, max_iter=2, verbose=False):
    # dep_graph is a networkx.Graph object representing inter-node
    # dependencies.
    # seq is the desired order of execution.
    set_priorities(dep_graph, seq)
    if verbose:
        print dep_graph.nodes(data=True)
    iternum = 1 # Starting iteration number
    current_time = 0
    schedule = {}
    found = False
    while iternum <= max_iter:
        #not finished(dep_graph, max_iter):
        if verbose:
            print 'Scheduling for time:', current_time
        schedule[current_time] = []
        for n in dep_graph.nodes_iter():
            if verbose:
                print 'Check:', n
            if can_schedule(dep_graph, n, max_iter):
                schedule[current_time].append(n)
        if verbose:
            print 'Scheduling:', schedule[current_time]
        for n in schedule[current_time]:
            # Execute the nodes in slist
            dep_graph.node[n]['iteration'] += 1
        if (not found) and find_count(dep_graph, 2):
            found = True
            print 'S-Ov =', current_time
        if finished(dep_graph, iternum):
            # Iteration finished. Increment count.
            if iternum == 1:
                print 'S =', current_time
            iternum += 1
        # Advance time
        current_time += 1
    return schedule

def test_seq_nodeid(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    #nlist = [ 3, 5, 7, 10 ]
    nlist = [ 5, 7, 10 ]
    dlist = [ 1, 2, 3 ]
    
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        for d in dlist:
            print '[D%d]'%(d)
            infilename = deployments + "/nodes" + str(n)
            infilename += "degree" + str(d) + "/topology.txt"
            print "Processing", infilename
            G = makeGraph(infilename, n*n)
            schedule = get_schedule(G, range(n*n), n*n, 2, verbose)
            if verbose:
                print schedule

def test_seq_multiple(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    matdir = os.getenv('HOME') + '/Dropbox/tecs/scripts/figures'
    #nlist = range(3, 16)
    nlist = [ 7, 10 ]
    
    dlist = [ 1, 2, 3 ]
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        matfilename = matdir + '/seqs_' + str(n) + '.mat' 
        print 'Loading', matfilename, '...'
        params = sio.loadmat(matfilename)
        seq = params['seq']
        for d in dlist:
            # Setup commonly used filename variables
            print 'Degree: ', d
            infilename = deployments + "/nodes" + str(n)
            infilename += "degree" + str(d) + "/topology.txt"
            print "Processing", infilename
            G = makeGraph(infilename, n*n)
            for i in range(len(seq)):
                print 'Sequence:', i
                seqlist = map(lambda x: int(x)-1, seq[i,:])
                schedule = get_schedule(G, seqlist, n*n, 2, verbose)
                if verbose:
                    print schedule

def _convertToList(right_n, startnode=0):
    seq = [ startnode ]
    pr = 0
    N = len(right_n)
    while pr < N-1:
        # Next node in ring
        pr += 1
        startnode = right_n[startnode]
        seq += [ startnode ]
    return seq

def test_seq_ring(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    #nlist = [ 3, 5, 7, 10 ]
    #nlist = [ 5, 7, 10 ]
    nlist = [ 7, 10 ]
    dlist = [ 1, 2, 3 ]
    
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        for d in dlist:
            print '[D%d]'%(d)
            infilename = deployments + "/nodes" + str(n)
            infilename += "degree" + str(d) + "/topology.txt"
            print "Processing", infilename
            right_n = get_ring(infilename, n*n)
            seq_n = _convertToList(right_n, 0)
            print 'Sequence:', seq_n
            G = makeGraph(infilename, n*n)
            schedule = get_schedule(G, seq_n, n*n, 2, verbose)
            if verbose:
                print schedule

def __getPlotDir(exp, ops=[]):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl/'
    logdir = rootdir + exp + '/sim/plots/'
    for op in ops:
        logdir += op + "/"
    return logdir

def _convertToSequence(filename):
    fin = open(filename)
    reader = csv.reader(fin, delimiter='\t')
    seq_n = []
    for row in reader:
        seq_n += [ int(row[0]) ]
    fin.close()
    return seq_n

def test_seq_dynamic(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew/"
    nlist = [ 7 ]
    dlist = [ 2 ]
    #dlist = [ 1, 2, 3 ]
    #runs = range(10)
    runs = [ 0 ]
    exp = 'FastCyclic'
    oplist = []
    oplist += [[ 'dynamic', 'WC', 'ring', 'alphaset1' ]]
    oplist += [[ 'dynamic', 'WC', 'timestamps', 'alphaset1' ]]
    oplist += [[ 'dynamic', 'WC', 'timestamps', 'relax', 'alphaset1' ]]
    for ops in oplist:
        print ops
        plotdir = __getPlotDir(exp, ops)
        for n in nlist:
            print 'Sensor Grid: %d x %d' % (n, n)
            for d in dlist:
                print '[D%d]'%(d)
                deployname = "nodes" + str(n) + "degree" + str(d)
                infilename = deployments + deployname + "/topology.txt"
                print "Processing", infilename
                G = makeGraph(infilename, n*n)
                for r in runs:
                    for iteration in range(10):
                        seqfile = plotdir + deployname + "/run"
                        seqfile += str(r) + "/schedule" + str(iteration+1) + ".txt"
                        seq_n = _convertToSequence(seqfile)
                        print 'Iteration:', iteration
                        schedule = get_schedule(G, seq_n, n*n, 2, verbose)
                        if verbose:
                            print schedule

def test_seq_greedy(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    #nlist = [ 3, 5, 7, 10 ]
    nlist = [ 5, 7, 10 ]
    dlist = [ 1, 2, 3 ]
    
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        for d in dlist:
            print '[D%d]'%(d)
            infilename = deployments + "/nodes" + str(n)
            infilename += "degree" + str(d) + "/topology.txt"
            print "Processing", infilename
            G = makeGraph(infilename, n*n)
            seq = GetSequence(G, verbose)
            if verbose:
                print 'Greedy Sequence:', seq
            schedule = get_schedule(G, seq, n*n, 2, verbose)
            if verbose:
                print schedule

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
    #test_seq_nodeid(verbose)
    #test_seq_multiple(verbose)
    #test_seq_ring(verbose)
    test_seq_dynamic(verbose)
    #test_seq_greedy(verbose)

# for f in *.txt; do python ~/Dropbox/actuation/topo_to_ring_subopt.py $f ; done
