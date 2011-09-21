import csv
import sys
import os
import getopt
import time

import networkx as nx

#from create_ring import *

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

def _canSchedule(dep_graph, n):
    if len(dep_graph.node[n]['pr']) == 0:
        # No more scheduling for this node
        return False
    for neighbor in dep_graph.neighbors(n):
        p = dep_graph.node[n]['pr'][0]
        if len(dep_graph.node[neighbor]['pr']) == 0:
            # This neighbor has been scheduled for all iterations
            continue
        p_nbr = dep_graph.node[neighbor]['pr'][0]
        if p_nbr < p:
            # This neighbor must be scheduled before n
            return False
    return True

def _allDone(G):
    for n in G.nodes_iter():
        if len(G.node[n]['pr']) > 0:
            return False
    return True

def _extractSchedule(dep_graph, outfilename, verbose=False):
    # dep_graph is a networkx.Graph object representing inter-node
    # dependencies.
    outf = open(outfilename, 'w')
    outf.write('# Iteration count vs schdeuling step\n')
    if verbose:
        print 'Input graph with scheduled node times:'
        print dep_graph.nodes(data=True)
    iternum = 1 # Starting iteration number
    current_time = 0
    schedule = {}
    found = False
    while not _allDone(dep_graph):
        if verbose:
            print 'Scheduling for time:', current_time
        schedule[current_time] = []
        for n in dep_graph.nodes_iter():
            if _canSchedule(dep_graph, n):
                schedule[current_time].append(n)
        if verbose:
            print 'Scheduling:', schedule[current_time]
        for n in schedule[current_time]:
            # Execute the nodes in slist
            dep_graph.node[n]['iteration'] += 1
            dep_graph.node[n]['pr'] = dep_graph.node[n]['pr'][1:]
        if (not found) and find_count(dep_graph, 2):
            found = True
            print 'S-Ov =', current_time
        if finished(dep_graph, iternum):
            # Iteration finished. Increment count.
            outf.write('%d\t%d\n'%(iternum,current_time))
            if iternum == 1:
                print 'S =', current_time
            iternum += 1
        # Advance time
        current_time += 1
    outf.close()
    return schedule

def _initGraph(G, nodes, max_iter=100):
    for (n, objn) in nodes.iteritems():
        schedtimes = objn.schedule.values()
        schedtimes.sort()
        # Clip the schedule times to max_iter iterations only
        G.node[n]['pr'] = schedtimes[0:max_iter]
        G.node[n]['iteration'] = 0

def ExtractDynamicSchedule(nodes, deploymentdir, outfilename, max_iter=100, verbose=False):
    infilename = deploymentdir + '/topology.txt'
    G = makeGraph(infilename, len(nodes))
    _initGraph(G, nodes, max_iter)
    return _extractSchedule(G, outfilename, verbose)

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

# for f in *.txt; do python ~/Dropbox/actuation/topo_to_ring_subopt.py $f ; done
