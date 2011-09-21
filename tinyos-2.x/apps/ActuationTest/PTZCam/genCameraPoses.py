#! /usr/bin/env python

import sys
import math
import getopt
import random
import pfloat
import perm_comb as gen

# 10x5 grid
GRID_X = 10
GRID_Y = 5

# Max camera range in m
RANGE = 0.8

# Number of nodes
NUM_NODES = 25

# Number of simulations
NUM_EXPERIMENTS = 10

def GetPoses(gridpoints, numnodes, n):
    # Generate all combinations of size='numnodes' from list 'gridpoints'.
    # Return 'n' random combinations from this list.
    print "Generating poses from:"
    print gridpoints
    print "Number of nodes: ", str(numnodes)
    rawlist = [ ]
    for item in gen.CombinationEnumerator(gridpoints, numnodes):
        rawlist.append(item)
    # Choose 'n' items from rawlist and return it to caller
    if n <= len(rawlist):
        return random.sample(rawlist, n)
    else:
        return [ ]

def CreateKernel(width):
    kernel = []
    for i in range(-width,width+1):
        for j in range(-width,width+1):
            dist = math.sqrt(i*i + j*j)
            kernel.append(dist)
    return kernel

def Merge(list1, list2):
    ret = [ ]
    for i in range(len(list1)):
        ret.append((list1[i], list2[i]))
    return ret

######## Pose file layout ############
#void get_pose(uint16_t node, pose2d_t *p) {
#    switch (node) {
#        case %id%:
#        {
#            p->loc.x = %x%*100;
#            p->loc.y = %y%*100;
#            p->a = %a%;
#           break;
#       }
#       ... repeat ...
#       default:
#       {
#           p->loc.x = 0;
#           p->loc.y = 0;
#            p->a = 0;
#            break;
#        }
#    }
#}
def _writeCase(file, tabs, id, x, y, a):
    casestr = tabs + "\t{\n"
    file.write(casestr)
    casestr = tabs + "\t\tp->loc.x = " + str(x) + ";\n"
    file.write(casestr)
    casestr = tabs + "\t\tp->loc.y = " + str(y) + ";\n"
    file.write(casestr)
    casestr = tabs + "\t\tp->a = " + str(a) + ";\n"
    file.write(casestr)
    casestr = tabs + "\t\tbreak;\n"
    file.write(casestr)
    casestr = tabs + "\t}\n"
    file.write(casestr)

class PoseFile:
    def __init__(self, grid_x, grid_y, verbose = False):
        self.grid_x = grid_x
        self.grid_y = grid_y
        self.verbose = verbose

    def _getNodeLocation(self, loc):
        x = loc % self.grid_x
        y = loc / self.grid_x
        return (x, y)

    def Generate(self, filename, node_locations):
        # 'node_locations' is a list of (node, location) tuples
        print "Generating pose file for grid ", str(self.grid_x), "x", str(self.grid_y)
        print "Filename: ", filename
        wf = open(filename, 'w')
        wf.write("\nvoid get_pose(uint16_t node, pose2d_t *p) {\n")
        wf.write("\tswitch (node) {\n");
        for (id, loc) in node_locations:
            casestr = "\t\tcase " + str(id) + ":\n"
            wf.write(casestr)
            (x, y) = self._getNodeLocation(loc)
            _writeCase(wf, '\t', id, int(x*100), int(y*100), 0)
        casestr = "\t\tdefault:\n"
        wf.write(casestr)
        _writeCase(wf, '\t', id, 0, 0, 0)
        casestr = "\t}\n}\n\n"
        wf.write(casestr)
        wf.close()

class TopologyFile:
    def __init__(self, grid_x, grid_y, 
                 noderange, verbose = False):
        self.grid_x = grid_x
        self.grid_y = grid_y
        self.gridsize = grid_x * grid_y
        self.range = 2.0*noderange
        self.kernelwidth = int(math.floor(2.0*noderange))
        self.kernel = CreateKernel(self.kernelwidth)
        self.verbose = verbose

    def _getNodeLocation(self, loc):
        x = loc % self.grid_x
        y = loc / self.grid_x
        return (x, y)

    def _getLocationIndex(self, i, j):
        return (j*self.grid_x + i)

    def _getNodeAt(self, i, j, node_locations):
        nloc = self._getLocationIndex(i, j)
        for (n, l) in node_locations:
            if l == nloc:
                return n
        return None

    def _genLinkString(self, n1, n2):
        # Generate a random link gain value between [-40.0,-50.0]
        # 'n1' and 'n2' are node ids
        gain = -(float(random.randint(0, 10)) + 40.0)
        linkstr = str(n1) + ' ' + str(n2) + ' '
        linkstr += str(gain)
        return linkstr

    def _outsideGrid(self, ni, nj):
        rx = range(self.grid_x)
        ry = range(self.grid_y)
        if ni not in rx:
            return True
        if nj not in ry:
            return True
        return False

    def PlotGraph(self, basefilename, node_locations, neighbors):
        locfilename = basefilename + "_loc.dat"
        locfile = open(locfilename, 'w')
        adjfilename = basefilename + "_adj.dat"
        adjfile = open(adjfilename, 'w')
        print "Writing plot file: ", locfilename
        print "Writing plot file: ", adjfilename
        for (node, loc) in node_locations:
            (i, j) = self._getNodeLocation(loc)
            locstr = str(i) + '\t' + str(j)
            locfile.write(locstr + '\n')
            adjstr = ""
            for n in range(len(node_locations)):
                if n in neighbors[node]:
                    adjstr += "1 "
                else:
                    adjstr += "0 "
            adjfile.write(adjstr + '\n')
            if self.verbose:
                print locstr
                print adjstr
        locfile.close()
        adjfile.close()

    def SetRange(self, noderange):
        self.range = 2.0*noderange
        self.kernelwidth = int(math.floor(2.0*noderange))
        self.kernel = CreateKernel(self.kernelwidth)

    def Generate(self, filename, node_locations):
        # 'node_locations' is a list of node locations ordered by their ID's
        print "Generating topology file:"
        print "Parameter: Grid ", str(self.grid_x), "x", str(self.grid_y)
        print "Paramter: Node range ", str(self.range/2)
        print "File name: ", filename
        wf = open(filename, 'w')
        total_ncount = 0
        neighbors = { }
        for (node, loc) in node_locations:
            # Repeat this for each (node, location)
            (i, j) = self._getNodeLocation(loc)
            idx = -1
            neighbors[node] = [ ]
            for x in range(-self.kernelwidth, self.kernelwidth+1):
                for y in range(-self.kernelwidth, self.kernelwidth+1):
                    # Use ditance kernel to find nodes within range
                    idx = idx + 1
                    ni = i+x
                    nj = j+y
                    if ni==i and nj==j:
                        continue
                    if self._outsideGrid(ni, nj):
                        continue
                    n_node = self._getNodeAt(ni, nj, node_locations)
                    if n_node == None:
                        continue
                    if self.kernel[idx] < self.range:
                        # There is a link between node and n_node
                        neighbors[node].append(n_node)
                        total_ncount = total_ncount + 1
                        linkstr = self._genLinkString(node, n_node)
                        wf.write(linkstr + '\n')
                        if self.verbose:
                            print linkstr
        avg = total_ncount/float(self.grid_x*self.grid_y)
        print 'Density(',str(self.range/2),'): ',str(avg)
        wf.close()
        return neighbors

class FileGenerator:
    def __init__(self, noderange, verbose = False):
        self.noderange = noderange
        self.verbose = verbose
        self.pose_file = PoseFile(GRID_X, GRID_Y, verbose)
        self.topo_file = TopologyFile(GRID_X, GRID_Y, noderange, verbose)

    def Create(self, doPlot):
        if (NUM_NODES % 2) == 1:
            n1 = int((NUM_NODES + 1) / 2)
            n2 = int(NUM_NODES/2)
        else:
            n1 = int(NUM_NODES/2)
            n2 = int(NUM_NODES/2)
        gridpoints = int(GRID_X*GRID_Y/2)
        nlist1 = GetPoses(range(gridpoints), n1, NUM_EXPERIMENTS)
        nlist2 = GetPoses(range(gridpoints, GRID_X*GRID_Y), n2, NUM_EXPERIMENTS)
        if self.verbose:
            print "List of locations 1: "
            print nlist1
            print "List of locations 2: "
            print nlist2
        for i in range(len(nlist1)):
            nlist1[i].extend(nlist2[i])
        if self.verbose:
            print "Complete list: "
            print nlist1
        for i in range(len(nlist1)):
            if self.verbose:
                print "Merging node ids with locations.."
            list_i = Merge(range(NUM_NODES), nlist1[i])
            posefile = "topology/camera_pose_" + str(i) + ".h";
            topofile = "topology/camera_topo_" + str(i) + ".txt";
            self.pose_file.Generate(posefile, list_i)
            neighbors = self.topo_file.Generate(topofile, list_i)
            if doPlot:
                plotfile = "topology/camera_pose_" + str(i)
                self.topo_file.PlotGraph(plotfile, list_i, neighbors)

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
    f = FileGenerator(RANGE, verbose)
    f.Create(True)

    #r = pfloat.frange(0.6, 1.6, 0.1)
    #rid = 0
    #for i in r:
    #    filename = 'trytopo' + str(rid) + '.txt'
    #    t.SetNewFile(filename, gridsize, r[rid])
    #    t.Generate()
    #    rid = rid + 1

