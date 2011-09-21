#! /usr/bin/env python

import sys
import math
import getopt
import random
import pfloat

def CreateKernel(width):
    kernel = []
    for i in range(-width,width+1):
        for j in range(-width,width+1):
            dist = math.sqrt(i*i + j*j)
            kernel.append(dist)
    return kernel

class TopologyFile:
    def __init__(self, topofile, gridsize, 
                 noderange, verbose = False):
        self.topofile = topofile
        self.gridsize = gridsize
        self.range = 2.0*noderange
        self.kernelwidth = int(math.floor(2.0*noderange))
        self.kernel = CreateKernel(self.kernelwidth)
        self.verbose = verbose
        if self.verbose:
            print "Creating a new topology file: ", topofile
            print "Parameters: Grid ", str(gridsize), "x", str(gridsize)
            print "Paramters: Node range ", str(noderange)

    def SetNewFile(self, topofile, gridsize, noderange):
        self.topofile = topofile
        self.gridsize = gridsize
        self.range = 2.0*noderange
        self.kernelwidth = int(math.floor(2.0*noderange))
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
        neighbors = 0
        for i in range(self.gridsize):
            for j in range(self.gridsize):
                # Repeat this for each node
                idx = -1
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
                            neighbors = neighbors + 1
                            n1 = self.GetNodeId(i, j)
                            n2 = self.GetNodeId(ni, nj)
                            linkstr = self.GenLinkString(n1, n2)
                            wf.write(linkstr)
                            if self.verbose:
                                print linkstr
        avg = neighbors/float(self.gridsize*self.gridsize)
        print 'Density(',str(self.gridsize),',',str(self.range/2),'): ',str(avg)
        wf.close()

    def GetActualDensity(self):
        neighbors = 0
        for i in range(self.gridsize):
            for j in range(self.gridsize):
                # Repeat this for each node
                idx = -1
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
                            neighbors = neighbors + 1
                            n1 = self.GetNodeId(i, j)
                            n2 = self.GetNodeId(ni, nj)
        avg_density = neighbors/float(self.gridsize*self.gridsize)
        return avg_density

######################################################################
# Testing + stand-alone use to parse files from a list given manually 
######################################################################

if (__name__ == '__main__'):
    try:
        opts, args = getopt.getopt(sys.argv[1:], "vg:", ["verbose", "grid="])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    gridsize = None
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-g", "--grid"):
            gridsize = int(a)
    if gridsize == None:
        gridsize = 3
    t = TopologyFile("trytopo.txt", gridsize, 0.6, verbose)
    r = pfloat.frange(0.6, 1.6, 0.1)
    rid = 0
    for i in r:
        filename = 'trytopo' + str(rid) + '.txt'
        t.SetNewFile(filename, gridsize, r[rid])
        t.Generate()
        rid = rid + 1

