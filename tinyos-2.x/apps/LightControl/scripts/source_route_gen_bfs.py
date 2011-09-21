import csv
import sys
import os
import getopt
import time

import networkx as nx
import scipy.io as sio

from greedycolor import *

max_len = 0

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

def read_topo(filename, numNodes=None):
    fin = open(filename)
    reader = csv.reader(fin,delimiter=' ')
    graph = dict()
    for row in reader:
        if numNodes != None:
            if (int(row[0])>=numNodes) or (int(row[1])>=numNodes):
                # Ignore nodes with id's greater than the limit
                continue
        if int(row[0]) not in graph:
            graph[int(row[0])] = [int(row[1])]
        else:
            graph[int(row[0])] += [int(row[1])]
    fin.close()
    return graph

def _isstr(x):
    if isinstance(x, str):
        return x
    else:
        return str(x)

def csvstr(listn):
    return reduce(lambda x,y: _isstr(x)+','+_isstr(y), listn)

def create_route_file(G, destfilename, outfilename, N, verbose=False):
    global max_len
    ARGS = "(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len)"
    outf = open(outfilename, "w") 
    print 'Writing to', outfilename
    print >>outf, "#ifndef _ROUTES_H_"
    print >>outf, "#define _ROUTES_H_\n"
    dest_graph = read_topo(destfilename, N);
    for (node, destinations) in dest_graph.iteritems():
        writestr = "int8_t fill_route" + str(node) + ARGS + "{"
        print >>outf, writestr
        print >>outf, "\tswitch (dest) {"
        if verbose:
            print 'Path from %d to:'%(node)
        paths = nx.shortest_path(G, node)
        for dest in destinations:
            if verbose:
                print '[%d]: %s'%(dest, paths[dest])
            print >>outf, "\t\tcase %d: {"%(dest)
            hops = paths[dest][1:]
            hops.reverse()
            # Store the max length of path seen so far
            max_len = max(len(hops),max_len)
            print >> outf, "\t\t\tif (max_len <",len(hops),") return -1;"
            ptr = 0
            for h in hops:
                print >>outf, "\t\t\thops[",ptr,"] =",h,";"
                ptr += 1
            print >>outf, "\t\t\treturn",ptr,";"
            print >>outf, "\t\t}" # End of case for this destination
        print >>outf, "\t\tdefault: {"
        print >>outf, "\t\t\treturn -1;"
        print >>outf, "\t\t}"
        print >>outf, "\t}\n\treturn -1;\n}\n"  # End of switch statement and function
        if verbose:
            print '==================================='
    print >>outf, "int8_t fill_route(am_addr_t dest, nx_am_addr_t *hops, int8_t max_len) {"
    print >>outf, "\tswitch (TOS_NODE_ID) {"
    for node in dest_graph.iterkeys():
        print >>outf, "\t\tcase %d: return fill_route%d(dest,hops,max_len);"%(node,node)
    print >>outf, "\t\tdefault: return -1;"
    print >>outf, "\t}\n\treturn -1;\n}\n"  # End of switch statement and function
    print >>outf, "#endif"
    outf.close()

def _createSourceConfig(outfilename, max_len=4):
    outf = open(outfilename, 'w')
    print 'Writing to',outfilename
    print >>outf, "#ifndef _SRC_CONFIG_H_"
    print >>outf, "#define _SRC_CONFIG_H_\n"
    print >>outf, "enum {"
    print >>outf, "\tSRC_MAX_HOPS =",max(max_len,4),","
    print >>outf, "};"
    print >>outf, "#endif"
    outf.close()

def create_all(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    global max_len
    max_len = 0
    #nlist = range(3, 16)
    nlist = [ 3, 5, 7, 10 ]
    
    dlist = [ 1, 2, 3, 4 ]
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        infilename = deployments + "/nodes" + str(n) + "degree1/topology.txt"
        print "Processing", infilename
        G = makeGraph(infilename, n*n)
        for d in dlist:
            # Setup commonly used filename variables
            print 'Degree: ', d
            deployname = "/nodes" + str(n) + "degree" + str(d)
            deploymentdir = deployments + deployname
            topofilename = deploymentdir + "/topology.txt"
            routefilename = deploymentdir + "/routes.h"
            max_len = 0
            create_route_file(G, topofilename, routefilename, n*n, verbose)
            topofilename = deploymentdir + "/ring_topology.txt"
            routefilename = deploymentdir + "/ring_routes.h"
            create_route_file(G, topofilename, routefilename, n*n, verbose)
            print 'Max path length -', max_len
            srcroutefile = deploymentdir + '/src_route_config.h'
            _createSourceConfig(srcroutefile, max_len)
    print '----------------------------------'
    print 'Maximum path length:', max_len
    print '----------------------------------'
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        for d in dlist:
            # Setup commonly used filename variables
            print 'Degree: ', d
            print "Processing", infilename
            deployname = "/nodes" + str(n) + "degree" + str(d)
            deploymentdir = deployments + deployname
            infilename = deploymentdir + "/topology.txt"
            G = makeGraph(infilename, n*n)
            topofilename = deploymentdir + "/ring_topology.txt"
            routefilename = deploymentdir + "/ring_routes_ie.h"
            max_len = 0
            create_route_file(G, topofilename, routefilename, n*n, verbose)
            print 'Max path length -', max_len
            srcroutefile = deploymentdir + '/src_route_config_ie.h'
            _createSourceConfig(srcroutefile, max_len)
    print '----------------------------------'
    print 'Maximum path length:', max_len
    print '----------------------------------'

def _createRingFile(outfilename, seq_n):
    outf = open(outfilename, 'w')
    print 'Writing to',outfilename
    N = len(seq_n)
    right_n = [0]*N
    for i in range(N):
        currnode = seq_n[i]
        nextnode = seq_n[(i+1)%N]
        right_n[currnode] = nextnode
    print >>outf, "#ifndef _RING_H_"
    print >>outf, "#define _RING_H_\n"
    print >>outf, "const am_addr_t right_n [",len(right_n),"]={",csvstr(right_n),"};"
    print >>outf, "#endif"
    outf.close()

def _createRingTopology(filename, seq_n):
    outf = open(filename, 'w')
    N = len(seq_n)
    for i in range(N):
        currnode = seq_n[i]
        nextnode = seq_n[(i+1)%N]
        print >>outf, '%d %d'%(currnode,nextnode)
        print >>outf, '%d %d'%(nextnode,currnode)
    outf.close()

def create_seq_routes(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    matdir = os.getenv('HOME') + '/Dropbox/tecs/scripts/figures'
    global max_len
    max_len = 0
    nlist = [ 7, 10 ]
    dlist = [ 1, 2, 3, 4 ]
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        matfilename = matdir + '/seqs_' + str(n) + '.mat' 
        print 'Loading', matfilename, '...'
        params = sio.loadmat(matfilename)
        seq = params['seq']
        for d in dlist:
            # Setup commonly used filename variables
            print 'Degree: ', d
            deployname = "/nodes" + str(n) + "degree" + str(d)
            deploymentdir = deployments + deployname
            infilename = deploymentdir + "/topology.txt"
            print "Processing", infilename
            G = makeGraph(infilename, n*n)
            for i in range(len(seq)):
                print 'Sequence:', i
                seqlist = map(lambda x: int(x)-1, seq[i,:])
                ringfilename = deploymentdir + "/ring"+ str(i+1) +".h"
                _createRingFile(ringfilename, seqlist)
                topofilename = deploymentdir + "/seq" + str(i+1) + "_topology.txt"
                _createRingTopology(topofilename, seqlist)
                routefilename = deploymentdir + "/ring_routes_ie"+ str(i+1) +".h"
                max_len = 0     # Reset max_len
                create_route_file(G, topofilename, routefilename, n*n, verbose)
                srcroutefile = deploymentdir+'/src_route_config_ie'+str(i+1)+'.h'
                _createSourceConfig(srcroutefile, max_len)
            i = len(seq)
            print 'Sequence:', i
            seqlist = range(n*n)
            ringfilename = deploymentdir + "/ring"+ str(i+1) +".h"
            _createRingFile(ringfilename, seqlist)
            topofilename = deploymentdir + "/seq" + str(i+1) + "_topology.txt"
            _createRingTopology(topofilename, seqlist)
            routefilename = deploymentdir + "/ring_routes_ie"+ str(i+1) +".h"
            max_len = 0     # Reset max_len
            create_route_file(G, topofilename, routefilename, n*n, verbose)
            srcroutefile = deploymentdir+'/src_route_config_ie'+str(i+1)+'.h'
            _createSourceConfig(srcroutefile, max_len)
            i += 1
            print 'Sequence:', i
            seqlist = GetSequence(G, verbose)
            ringfilename = deploymentdir + "/ring"+ str(i+1) +".h"
            _createRingFile(ringfilename, seqlist)
            topofilename = deploymentdir + "/seq" + str(i+1) + "_topology.txt"
            _createRingTopology(topofilename, seqlist)
            routefilename = deploymentdir + "/ring_routes_ie"+ str(i+1) +".h"
            max_len = 0     # Reset max_len
            create_route_file(G, topofilename, routefilename, n*n, verbose)
            srcroutefile = deploymentdir+'/src_route_config_ie'+str(i+1)+'.h'
            _createSourceConfig(srcroutefile, max_len)
    print '----------------------------------'
    print '----------------------------------'
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        infilename = deployments + "/nodes" + str(n) + "degree1/topology.txt"
        print "Processing", infilename
        G = makeGraph(infilename, n*n)
        matfilename = matdir + '/seqs_' + str(n) + '.mat' 
        print 'Loading', matfilename, '...'
        params = sio.loadmat(matfilename)
        seq = params['seq']
        for d in dlist:
            # Setup commonly used filename variables
            print 'Degree: ', d
            deployname = "/nodes" + str(n) + "degree" + str(d)
            deploymentdir = deployments + deployname
            for i in range(len(seq)):
                print 'Sequence:', i
                topofilename = deploymentdir + "/seq" + str(i+1) + "_topology.txt"
                routefilename = deploymentdir + "/ring_routes"+ str(i+1) +".h"
                max_len = 0
                create_route_file(G, topofilename, routefilename, n*n, verbose)
                srcroutefile = deploymentdir+'/src_route_config'+str(i+1)+'.h'
                _createSourceConfig(srcroutefile, max_len)
            i = len(seq)
            print 'Sequence:', i
            topofilename = deploymentdir + "/seq" + str(i+1) + "_topology.txt"
            routefilename = deploymentdir + "/ring_routes"+ str(i+1) +".h"
            max_len = 0
            create_route_file(G, topofilename, routefilename, n*n, verbose)
            srcroutefile = deploymentdir+'/src_route_config'+str(i+1)+'.h'
            _createSourceConfig(srcroutefile, max_len)
            i += 1
            print 'Sequence:', i
            topofilename = deploymentdir + "/seq" + str(i+1) + "_topology.txt"
            routefilename = deploymentdir + "/ring_routes"+ str(i+1) +".h"
            max_len = 0
            create_route_file(G, topofilename, routefilename, n*n, verbose)
            srcroutefile = deploymentdir+'/src_route_config'+str(i+1)+'.h'
            _createSourceConfig(srcroutefile, max_len)
    print '----------------------------------'
    print '----------------------------------'

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
    #create_all(verbose)
    create_seq_routes(verbose)

# for f in *.txt; do python ~/Dropbox/actuation/topo_to_ring_subopt.py $f ; done
