#! /usr/bin/env python

import sys
import math
import getopt
import random
import pfloat

def mean(l):
    if len(l) == 0:
        return 0
    return sum(l)/len(l)

def CreateKernel(width):
    kernel = []
    for i in range(-width,width+1):
        for j in range(-width,width+1):
            dist = math.sqrt(i*i + j*j)
            kernel.append(dist)
    return kernel

class TopologyFile:
    def __init__(self, verbose = False):
        self.verbose = verbose

    def SetNewFile(self, topofile, gridsize, noderange):
        self.topofile = topofile
        self.gridsize = gridsize
        self.range = noderange
        self.kernelwidth = int(math.floor(noderange))
        self.kernel = CreateKernel(self.kernelwidth)
        if self.verbose:
            print "Creating a new topology file: ", topofile
            print "Parameters: Grid ", str(gridsize), "x", str(gridsize)
            print "Paramters: Node range ", str(noderange)

    def GetNodeId(self, i, j):
        return (i*self.gridsize + j)

    def GenLinkString(self, n1, n2):
        # Generate a random link gain value between [-40.0,-55.0]
        gain = -(float(random.randint(0, 15)) + 40.0)
        linkstr = str(n1) + ' ' + str(n2) + ' '
        linkstr += str(gain) + '\n'
        return linkstr

    def OutsideGrid(self, ni, nj):
        r = range(self.gridsize)
        if ni not in r:
            return True
        if nj not in r:
            return True
        return False

    def Generate(self):
        wf = open(self.topofile, 'w')
        neighbors = []
        for i in range(self.gridsize):
            for j in range(self.gridsize):
                # Repeat this for each node
                idx = -1
                lnbrs = 0
                n1 = self.GetNodeId(i, j)
                for x in range(-self.kernelwidth, self.kernelwidth+1):
                    for y in range(-self.kernelwidth, self.kernelwidth+1):
                        idx = idx + 1
                        ni = i+x
                        nj = j+y
                        if ni==i and nj==j:
                            continue
                        if self.OutsideGrid(ni, nj):
                            continue
                        if self.kernel[idx] < self.range:
                            # There is a link between (i,j) and (ni,nj)
                            lnbrs += 1
                            n2 = self.GetNodeId(ni, nj)
                            linkstr = self.GenLinkString(n1, n2)
                            wf.write(linkstr)
                            if self.verbose:
                                print linkstr
                # Append the number of neighbors of node n1 to the list
                neighbors.append(lnbrs)
        avg = mean(neighbors)
        mi = min(neighbors)
        ma = max(neighbors)
        print 'Density(%d, %f): [%f, %f, %f]'%(self.gridsize,self.range,mi,avg,ma)
        wf.close()

    def GetActualDensity(self):
        neighbors = []
        for i in range(self.gridsize):
            for j in range(self.gridsize):
                # Repeat this for each node
                idx = -1
                lnbrs = 0
                n1 = self.GetNodeId(i, j)
                for x in range(-self.kernelwidth, self.kernelwidth+1):
                    for y in range(-self.kernelwidth, self.kernelwidth+1):
                        idx = idx + 1
                        ni = i+x
                        nj = j+y
                        if ni==i and nj==j:
                            continue
                        if self.OutsideGrid(ni, nj):
                            continue
                        if self.kernel[idx] < self.range:
                            # There is a link between (i,j) and (ni,nj)
                            lnbrs += 1
                            n2 = self.GetNodeId(ni, nj)
                # Append the number of neighbors of node n1 to the list
                neighbors.append(lnbrs)
        avg = mean(neighbors)
        return avg

    def GetAdjacencyMatrix(self):
        neighbors = {}
        for i in range(self.gridsize):
            for j in range(self.gridsize):
                # Repeat this for each node
                idx = -1
                lnbrs = []
                n1 = self.GetNodeId(i, j)
                for x in range(-self.kernelwidth, self.kernelwidth+1):
                    for y in range(-self.kernelwidth, self.kernelwidth+1):
                        idx = idx + 1
                        ni = i+x
                        nj = j+y
                        if ni==i and nj==j:
                            continue
                        if self.OutsideGrid(ni, nj):
                            continue
                        if self.kernel[idx] < self.range:
                            # There is a link between (i,j) and (ni,nj)
                            n2 = self.GetNodeId(ni, nj)
                            lnbrs.append(n2)
                # Append the number of neighbors of node n1 to the list
                neighbors[n1] = lnbrs
        return neighbors

    def PrintAdjMatrix(self, adj):
        wf = open(self.topofile, 'w')
        nlist = adj.keys()
        nlist.sort()
        N = len(nlist)
        for n in nlist:
            for i in range(N):
                is_nbr = 0
                if i in adj[n]:
                    is_nbr = 1
                wf.write(str(is_nbr)+' ')
            wf.write('\n')
        wf.close()

############################
# Testing + stand-alone use 
############################

if (__name__ == '__main__'):
    try:
        opts, args = getopt.getopt(sys.argv[1:], "v", ["verbose"])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
    t = TopologyFile(verbose)
    gridsizes = [ 5, 7, 10 ]
    radio_r = [ 1.1, 1.5, 2.1, 2.3, 2.9, 3.1 ]
    #radio_r = pfloat.frange(1.1, 1.5, 2.1, 2.3, 2.9, 3.1)
    for gr in gridsizes:
        rid = 0
        for r in radio_r:
            #filename = 'topo_' + str(gr) + '_d' + str(rid) + '.txt'
            filename = 'adj_' + str(gr) + '_d' + str(rid) + '.txt'
            t.SetNewFile(filename, gr, r)
            #t.Generate()
            adj = t.GetAdjacencyMatrix()
            t.PrintAdjMatrix(adj)
            rid += 1

