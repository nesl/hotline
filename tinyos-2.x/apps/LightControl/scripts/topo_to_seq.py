import sys
import os
import getopt
import csv

import networkx as nx
import scipy.io as sio
import numpy as np

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

def __createFile(outfilename, seqlist):
    outf = open(outfilename, "w") 
    print 'Writing to',outfilename
    print >>outf, "#ifndef _PRIORITY_H_"
    print >>outf, "#define _PRIORITY_H_\n"
    print >>outf, "uint32_t get_priority(am_addr_t nid) {"
    print >>outf, "\tswitch (nid) {"
    for pr in range(len(seqlist)):
        print >>outf, "\t\tcase",int(seqlist[pr]),": return",pr,";"
    print >>outf, "\t\tdefault: return 0;"
    print >>outf, "\t}\n\treturn 0;\n}"
    print >>outf, "#endif"
    outf.close()

def create_pr_file(seq, n, topofile, outfile):
    for i in range(len(seq)):
        outfilename = outfile + str(i+1) + ".h"
        seqlist = map(lambda x: int(x)-1, seq[i,:])
        print 'Original:',seq[i,:]
        print 'Fixed:',seqlist
        __createFile(outfilename, seqlist)
    i += 1
    outfilename = outfile + str(i+1) + ".h"
    __createFile(outfilename, range(n*n))
    i += 1
    G = makeGraph(topofile, n*n)
    seqlist = GetSequence(G)
    outfilename = outfile + str(i+1) + ".h"
    __createFile(outfilename, seqlist)

def create_all(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    matdir = os.getenv('HOME') + '/Dropbox/tecs/scripts/figures'
    #nlist = range(3, 16)
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
            baseringfile = deploymentdir + "/priority"
            topofile = deploymentdir + "/topology.txt"
            create_pr_file(seq, n, topofile, baseringfile)

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
    create_all(verbose)

# for f in *.txt; do python ~/Dropbox/actuation/topo_to_ring_subopt.py $f ; done
