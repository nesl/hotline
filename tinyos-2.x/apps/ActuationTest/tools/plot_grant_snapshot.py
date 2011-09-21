from ParseFile import *
import matplotlib
matplotlib.use('PDF')
import matplotlib.pyplot as plt
import numpy as np

def get_coordinates(point_list) :
	point_list.sort()
	y_coord = []
	y_min = []
	y_max = []

	for pair in point_list :
		if len(y_min) == 0 :
			y_min.append(pair[0])
			y_max.append(pair[1])
			y_coord.append(1);
		else :
			found_y = False;
			for idx in range(len(y_min)) :
				if pair[1] <= y_min[idx] :
					y_coord.append(idx + 1)
					found_y = True;
					y_min[idx] = pair[0]
					break
				elif pair [0] >= y_max[idx] :
					y_coord.append(idx + 1)
					found_y = True;
					y_max[idx] = pair[1]
					break;
			if not found_y :
				new_y = max(y_coord) + 1;
				y_coord.append(new_y)
				y_min.append(pair[0])
				y_max.append(pair[1])

	return [point_list, y_coord]
	
def plot_point_list(point_list, filename, verbose=False) :
    [x,y] = get_coordinates(point_list);
    max_x = 0;
    min_x = 2**32;
    for xx in x :
        if xx[0] < min_x :
            min_x = xx[0]
        if xx[1] > max_x :
            max_x = xx[1]
    max_x = max_x + 1;
    min_x = min_x - 1;
    max_y = max(y) + 1;
    min_y = 0;
    
    plt.clf()
    for idx in range(len(y)) :
        x[idx] = ( x[idx][0] - min_x, x[idx][1] - min_x )
        if verbose:
            print x[idx],y[idx]
        plt.plot(x[idx], (y[idx],y[idx]),'|-', mew=2, hold = True, lw=2)
    
    frame1 = plt.gca()
    plt.axis([0, max_x-min_x, min_y, max_y])
    frame1.axes.get_yaxis().set_ticks([])
    #plt.axis([min_x, max_x, min_y, max_y])
    plt.xlabel("Time (s)")
    plt.ylabel("Concurrent Locks")
    #plt.xticks( np.arange(max_x + 1) )
    #plt.yticks( np.arange(max_y + 1) )
    plt.savefig(filename)
    plt.show()

def plot_grant_release(infilename, outfilename, verbose=False) :
    simulation = True
    lf = LogFileParser(verbose, simulation)
    lf.ParseFile(infilename)
    (stats, tmsg) = lf.GetStats()
    xpairs = []
    for (n, nstat) in stats.iteritems():
        for i in range(10):
            xpairs.append( (nstat['granttimes'][i], nstat['releasetimes'][i]) )
    if verbose:
        print xpairs
    plot_point_list(xpairs,outfilename,verbose);




#plot_grant_release('/home/lucas/Dropbox/actuation/log0_strict', '/home/lucas/Dropbox/actuation/plot_strict.pdf')
plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/FastCyclic/sim/logs/alphaset1/nodes5degree1/run0.txt', 'plot_5.pdf')
plot_grant_release('/home/rahulb/projects/actuation/tinyos-2.x/apps/LightControl/FastCyclic/sim/logs/alphaset1/nodes10degree1/run0.txt', 'plot_10.pdf')
