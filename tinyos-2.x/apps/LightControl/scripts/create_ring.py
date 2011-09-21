
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

def get_ring(filename, N):
    graph = read_topo(filename,N);
    longest_cycle = find_longest_cycle(graph,0)
    #print longest_cycle
    full_cycle=insert_missing(graph, longest_cycle)
    #print full_cycle
    full_cycle = full_cycle[0]
    network_size = len(graph);
    left_n = []
    right_n = []
    for node in range(network_size) :
        node_idx = full_cycle.index(node)
        #print (node_idx - 1)% network_size, len(full_cycle	)
        left_n.append(full_cycle[(node_idx - 1)% network_size])
        right_n.append(full_cycle[(node_idx + 1)% network_size])
    return right_n

