import sys, os
import getopt
from ParseLogFile import *
import matplotlib
matplotlib.use('PDF')
import matplotlib.pyplot as plt
import numpy as np

def _plot_point_list(point_list, color_list, filename, verbose=False) :
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

def PlotSchedule(nodes, outfilename, startiter=0, verbose=False):
    xpairs = {}
    clist = [ 'b','g','r','c','m','y','k' ]
    enditer = startiter + len(clist)
    for (n,objn) in nodes.iteritems():
        xpairs[n] = []
        for i in range(startiter, enditer):
            xpairs[n].append( (objn.appstate.grant_times[i],
                objn.appstate.release_times[i]) )
    if verbose:
        print xpairs
    _plot_point_list(xpairs, clist, outfilename, verbose);

#################################################################
# Functions below are used only when executing this file directly
#################################################################
def __getLogDir(exp, ops=[]):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl/'
    logdir = rootdir + exp + '/sim/logs/'
    for op in ops:
        logdir += op + "/"
    return logdir

def __getPlotDir(exp, ops=[]):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl/'
    logdir = rootdir + exp + '/sim/plots/'
    for op in ops:
        logdir += op + "/"
    return logdir

def __extendDir(logdir, ops=[]):
    for op in ops:
        logdir += op + "/"
    return logdir

def __plotScheduleFromFile(infilename, outfilename, startiter=0, verbose=False):
    simulation = True
    lf = Parser(False, simulation)
    nodes = lf.Parse(infilename)
    PlotSchedule(nodes, outfilename, startiter, verbose)

def __runThis(exp, nlist, dlist, runs, ops, extraops, plotpfx=''):
    print 'Simulation:', exp
    logbase = __getLogDir(exp, ops)
    plotbase = __getPlotDir(exp, ops)
    for n in nlist:
        print 'Sensor grid: %d x %d'%(n,n)
        for d in dlist:
            print 'Degree: ', d
            for r in runs:
                # Setup commonly used filename variables
                print 'Run: ', r
                deployname = "nodes" + str(n) + "degree" + str(d) + "/"
                logdir = logbase + deployname
                logdir = __extendDir(logdir, extraops)
                logfilename = logdir + 'run' + str(r) + '.txt'
                #plotdir = plotbase + deployname
                #plotdir = __extendDir(plotdir, extraops)
                #plotfilename = plotdir + 'plot.pdf'
                plotfilename = 'plot_%s_%s_n%d_d%d_r%d.pdf'%(exp,plotpfx,n,d,r)
                __plotScheduleFromFile(logfilename, plotfilename, startiter,
                        verbose)
        print '----------------------------------'
    print '========================================='

def _createPlots(startiter=0, verbose=False):
    exp = 'FastCyclic'
    nlist = [ 7 ]
    dlist = [ 2 ]
    runs = [ 0 ]
    ops = [ 'static', 'WC', 'ring', 'alphaset1' ]
    extraops = [ 'seq5' ]
    __runThis(exp, nlist, dlist, runs, ops, extraops, extraops[0])
    #exp = 'Cyclic'
    #nlist = [ 7 ]
    #dlist = [ 2 ]
    #runs = [ 0 ]
    #ops = [ 'alphaset1' ]
    #extraops = []
    #__runThis(exp, nlist, dlist, runs, ops, extraops)

if (__name__ == '__main__'):
    try:
        opts, args = getopt.getopt(sys.argv[1:], "ves:", ["verbose", "errors",
            "start"])
    except getopt.GetoptError, err:
        # print help information and exit:
        print str(err) # will print something like "option -a not recognized"
        sys.exit(2)
    verbose = False
    list_errors = False
    startiter = 0
    for o, a in opts:
        if o in ("-v", "--verbose"):
            verbose = True
        elif o in ("-e", "--errors"):
            list_errors = True
        elif o in ("-s", "--start"):
            startiter = int(a)
    _createPlots(startiter, verbose)

#plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/FastCyclic/sim/logs/static/WC/ring/alphaset1/nodes7degree2/run0.txt', 'plot_7_2_static_ring.pdf', 0)
#plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/Cyclic/sim/logs/alphaset1/nodes5degree1/run0.txt', 'plot_5_cyclic_new.pdf', 0)
#plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/Cyclic/sim/logs/alphaset1/nodes10degree1/run0.txt', 'plot_10_cyclic_new.pdf', 0)
