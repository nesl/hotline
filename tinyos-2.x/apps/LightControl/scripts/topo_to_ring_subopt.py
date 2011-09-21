import csv
import sys
import os
import getopt
import time
MAX_ELAPSED_TIME = 1


def find_paths(graph, start, end, start_time, path=[]):
        #http://www.python.org/doc/essays/graphs/
        path = path + [start]
        if start == end:
            return [path]
        if not graph.has_key(start):
            return []
        paths = []
        for node in graph[start]:
            if node not in path:
                newpaths = find_paths(graph, node, end, start_time, path)
                for newpath in newpaths:
                    paths.append(newpath)
                    if len(newpath) == len(graph) :
						return [newpath]
				#uncomment the following lines if running into time problems
                if time.time() - start_time > MAX_ELAPSED_TIME :
					return paths
        return paths
        
def find_all_paths(graph, start, end):
	start_time = time.time()
	return find_paths(graph, start, end, start_time)
	

def find_longest_cycle(graph,startnode):
	longest_cycle = []
	longest_len = 0;
	cycles=[]
	for endnode in graph[startnode]:
		newpaths = find_all_paths(graph, startnode, endnode)
		for path in newpaths:
			if len(path) > longest_len :
				longest_len = len(path);
				longest_cycle = path
				if len(path) == len(graph) :
					return longest_cycle
	return longest_cycle	

def insert_missing(graph, cycle) :
	full_circuit = cycle[:]
	new_cycle = cycle[:]
	for node in graph :
		if node not in new_cycle :
			for neighbor in graph[node] :
				#print "node", node, "neighbor", neighbor
				if neighbor in cycle :
					new_cycle.insert(new_cycle.index(neighbor)+1,node);					
					#cycle.insert(cycle.index(node),neighbor);		
					full_circuit.insert(full_circuit.index(neighbor),node);					
					full_circuit.insert(full_circuit.index(node),neighbor);										
					break;
	return [new_cycle, full_circuit]

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
            graph[int(row[0])] = [int(row[1])] + graph[int(row[0])]
    fin.close()
    return graph




def _isstr(x):
    if isinstance(x, str):
        return x
    else:
        return str(x)+'L'

def csvstr(listn):
    return reduce(lambda x,y: _isstr(x)+','+_isstr(y), listn)

def create_ring_file(filename, outfilename, N):
	outf = open(outfilename, "w") 
	print "Processing", filename
	graph = read_topo(filename,N);
	longest_cycle = find_longest_cycle(graph,0)
	#print longest_cycle
	full_cycle=insert_missing(graph, longest_cycle)
	#print full_cycle
	with_intermediate = full_cycle[1]
	full_cycle = full_cycle[0]
	network_size = len(graph);
	left_n = []
	right_n = []
	next_hop_right = []
	next_hop_left = []
	for node in range(network_size) :
		node_idx = full_cycle.index(node)
		#print (node_idx - 1)% network_size, len(full_cycle	)
		
		left_n.append(full_cycle[(node_idx - 1)% network_size])
		right_n.append(full_cycle[(node_idx + 1)% network_size])
	for node in range(len(right_n)) :
		if node not in longest_cycle :
			next_hop_right.append(with_intermediate[with_intermediate.index(node) +1])
		else :
			next_hop_right.append(0xFFFF)
	for node in range(len(left_n)) :
		if left_n[node] not in longest_cycle :
			next_hop_left.append(with_intermediate[with_intermediate.index(node) -1])
		else :
			next_hop_left.append(0xFFFF)		
	print 'Writing to',outfilename
	print >>outf, "#ifndef _RING_H_"
	print >>outf, "#define _RING_H_\n"
	print >>outf, "const am_addr_t left_n [",len(left_n),"]={",csvstr(left_n),"};"
	print >>outf, "const am_addr_t right_n [",len(right_n),"]={",csvstr(right_n),"};"
	print >>outf, "const am_addr_t next_hop_left [",len(next_hop_left),"]={",csvstr(next_hop_left),"};\n"
	print >>outf, "const am_addr_t next_hop_right [",len(next_hop_right),"]={",csvstr(next_hop_right),"};\n"
	print >>outf, "#endif"
	outf.close()

def create_all(verbose=False):
    rootdir = os.getenv('MYTOSROOT') + '/apps/LightControl'
    deployments = rootdir + "/DeploymentsNew"
    nlist = range(3, 16)
    
    dlist = [ 1, 2, 3, 4 ]
    #dlist = [ 2, 3 ]
    for n in nlist:
        print 'Sensor Grid: %d x %d' % (n, n)
        for d in dlist:
            # Setup commonly used filename variables
            print 'Degree: ', d
            deployname = "/nodes" + str(n) + "degree" + str(d)
            deploymentdir = deployments + deployname
            topofilename = deploymentdir + "/topology.txt"
            ringfilename = deploymentdir + "/ring.h"
            create_ring_file(topofilename, ringfilename, n*n)

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
