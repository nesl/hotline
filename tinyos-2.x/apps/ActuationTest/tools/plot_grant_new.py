from ParseFile import *
import matplotlib
matplotlib.use('PDF')
import matplotlib.pyplot as plt
import numpy as np

def plot_point_list(point_list, color_list, filename, verbose=False) :
    max_x = 0
    min_x = 2**32
    ncount = 0
    for (n, xplist) in point_list.iteritems():
        ncount += 1
        if xplist[0][0] < min_x:
            # First grant time
            min_x = xplist[0][0]
        if xplist[-1][1] > max_x:
            # Last release time
            max_x = xplist[-1][1]
    max_x += 1
    min_x -= 1
    max_y = ncount + 1
    min_y = 0;
    
    plt.clf()
    for (n, xplist) in point_list.iteritems():
        cid = 0
        for xx in xplist:
            #plt.plot(xx, (n,n),'|-', mew=2, hold = True, lw=2)
            _xx = ( xx[0]-min_x, xx[1]-min_x )
            if verbose:
                print _xx, n
            plt.plot(_xx, (n+1,n+1), color_list[cid]+'|-', mew=1.5, hold=True, lw=2)
            cid += 1
    
    frame1 = plt.gca()
    plt.axis([0, max_x-min_x, min_y, max_y])
    #frame1.axes.get_yaxis().set_ticks([])
    #plt.axis([min_x, max_x, min_y, max_y])
    plt.xlabel("Time (s)")
    plt.ylabel("Node Identifiers")
    #plt.xticks( np.arange(max_x + 1) )
    #plt.yticks( np.arange(max_y + 1) )
    plt.savefig(filename)
    plt.show()

def plot_grant_release(infilename, outfilename, startiter=0, verbose=False):
    simulation = True
    lf = LogFileParser(False, simulation)
    lf.ParseFile(infilename)
    (stats, tmsg) = lf.GetStats()
    if verbose:
        print stats
    xpairs = {}
    clist = [ 'b','g','r','c','m','y','k' ]
    enditer = startiter + len(clist)
    for (n, nstat) in stats.iteritems():
        xpairs[n] = []
        for i in range(startiter, enditer):
            xpairs[n].append( (nstat['granttimes'][i], nstat['releasetimes'][i]) )
    if verbose:
        print xpairs
    plot_point_list(xpairs, clist, outfilename, verbose);


plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/FastCyclic/sim/logs/static/WC/ring/alphaset1/nodes7degree2/run0.txt', 'plot_7_2_static_ring.pdf', 0)
#plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/Cyclic/sim/logs/alphaset1/nodes5degree1/run0.txt', 'plot_5_cyclic_new.pdf', 0)
#plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/Cyclic/sim/logs/alphaset1/nodes10degree1/run0.txt', 'plot_10_cyclic_new.pdf', 0)
