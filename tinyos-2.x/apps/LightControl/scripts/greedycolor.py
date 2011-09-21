
import sys, os

import networkx as nx

def _setDefaultColor(G):
    for n in G.nodes_iter():
        G.node[n]['color'] = -1

def _getSortedNodes(G):
    # Sort nodes based on their degree
    degrees = {}
    for n in G.nodes_iter():
        d = len(G.neighbors(n))
        if d not in degrees:
            degrees[d] = []
        degrees[d].append(n)
    dlist = degrees.keys()
    dlist.sort()
    dlist.reverse()
    sortednodes = []
    for d in dlist:
        sortednodes += degrees[d]
    return sortednodes

def _adjacent(G, v, coloredlist):
    for n in G.neighbors(v):
        if n in coloredlist:
            return True
    return False

# Algorithm taken from:
# http://scienceblogs.com/goodmath/2007/06/graph_coloring_algorithms_1.php
def ColorGraph(G, verbose=False):
    # Color the graph G and store it as attributes of nodes
    _setDefaultColor(G)
    uncolored = _getSortedNodes(G)
    currentcolor = 0
    while len(uncolored) > 0:
        A = uncolored[0]
        uncolored = uncolored[1:]
        G.node[A]['color'] = currentcolor
        coloredWithCurrent = [ A ]
        for v in uncolored:
            if not _adjacent(G, v, coloredWithCurrent):
                G.node[v]['color'] = currentcolor
                coloredWithCurrent += [ v ]
                uncolored.remove(v)
        currentcolor += 1
    if verbose:
        print 'Colors used -', currentcolor

def _getSortedColors(colordict):
    c_len = {}
    for (c, nlist) in colordict.iteritems():
        l = len(nlist)
        if l not in c_len:
            c_len[l] = []
        c_len[l].append(c)
    lenkeys = c_len.keys()
    lenkeys.sort()
    lenkeys.reverse()
    sortedlist = []
    for l in lenkeys:
        sortedlist += c_len[l]
    return sortedlist

def GetSequence(G, verbose=False):
    # Convert graph coloring into a sequence
    ColorGraph(G, verbose)
    colordict = {}
    for n in G.nodes_iter():
        c = G.node[n]['color']
        if c not in colordict:
            colordict[c] = []
        colordict[c].append(n)
    clist = _getSortedColors(colordict)
    sequence = []
    for c in clist:
        sequence += colordict[c]
    return sequence
