#!/usr/bin/python

import sys
import random
from TOSSIM import *
from tinyos.tossim.TossimApp import *

numNodes = 9

n = NescApp()
t = Tossim(n.variables.variables())
r = t.radio()

f = open("topology/topo_3_d0.txt", "r")
lines = f.readlines()
for line in lines:
  s = line.split()
  if (len(s) > 0):
     r.add(int(s[0]), int(s[1]), float(s[2]))

for i in range(numNodes):
  m = t.getNode(i)
  for j in range (0, 100):
    m.addNoiseTraceReading(-105)
  m.createNoiseModel()


#t.addChannel("TestP1Eval", sys.stdout)
#t.addChannel("VirtualLockPEval", sys.stdout)
#t.addChannel("NeighborPEval", sys.stdout)
#t.addChannel("TransportPEval", sys.stdout)
t.addChannel("TestP1", sys.stdout)
t.addChannel("VirtualLockP", sys.stdout)
#t.addChannel("TransportP", sys.stdout)
#t.addChannel("NeighborP", sys.stdout)
#t.addChannel("NbrTrickleImplP", sys.stdout)
#t.addChannel("DipDataP", sys.stdout)
#t.addChannel("DipLogicP", sys.stdout)
#t.addChannel("AMDipP", sys.stdout)

for i in range(numNodes):
    t.getNode(i).bootAtTime(4 * t.ticksPerSecond() + 242119)
    #t.getNode(i).bootAtTime(23542399)
    #t.getNode(i).bootAtTime(random.randint(0,23512178) + 23542399)
    #t.getNode(i).bootAtTime(i * 23 + 23542399)

#for i in range(0,22600):
#    t.runNextEvent()
    
#while (t.runNextEvent()):
#    pass

#while t.time() < 1000*t.ticksPerSecond():
#    if ( t.runNextEvent() == 0 ):
#        break

var_list_confirm = []
for i in range(numNodes):
    var_list_confirm.append(t.getNode(i).getVariable("TestP1.done"))

testsum = 0
while(testsum < numNodes):
    testsum = 0
    t.runNextEvent()
    for n in var_list_confirm:
        testsum = testsum + n.getData()

