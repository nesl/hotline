#! /usr/bin/env python

import sys

class EventFields:
    def __init__(self, verbose=False, simulation=True):
        self.verbose = verbose
        # Default: Extract fields from a TOSSIM simulation log
        # DEBUG (<id>): .....
        # simulation=False: Extract from a mote log
        # <Timestamp(ms)> DEBUG (<id>): ....
        self.simulation = simulation
        self.log_dict = {}

    def ExtractId(self, s):
        # Extract id=n from string '(n):'
        fields = s.split('(')
        fields = fields[1].split(')');
        return int(fields[0])

    def ExtractEvent(self, s):
        # Extract events from string 's_s_...'
        fields = s.split('_')
        return fields

    def ConvertTime(self, s):
        # Convert time to seconds from 'hh:mm:ss.ms'
        fields = s.split(':')
        hh = int(fields[0])
        mm = int(fields[1])
        ss = float(fields[2])
        return ( (hh*60*60)+(mm*60)+ss )

    def _getSimFields(self, line):
        # line: read from a log file
        self.log_dict = {}
        rawfields = line.split()
        self.log_dict['node'] = self.ExtractId(rawfields[1])
        logfields = self.ExtractEvent(rawfields[2])
        self.log_dict['type'] = logfields[0]
        self.log_dict['time'] = self.ConvertTime(logfields[1])
        self.log_dict['rest'] = logfields[2:]
        if self.verbose:
            print self.log_dict
        return self.log_dict

    def _getMoteFields(self, line):
        # line: read from a log file
        # <Timestamp(ms)> DEBUG (<id>): ....
        self.log_dict = {}
        rawfields = line.split()
        self.log_dict['time'] = float(rawfields[0])/1000.0
        self.log_dict['node'] = self.ExtractId(rawfields[2])
        logfields = self.ExtractEvent(rawfields[3])
        self.log_dict['type'] = logfields[0]
        self.log_dict['motetime'] = int(logfields[1])
        self.log_dict['rest'] = logfields[2:]
        if self.verbose:
            print self.log_dict
        return self.log_dict

    def Get(self, line):
        if self.simulation:
            return self._getSimFields(line)
        else:
            return self._getMoteFields(line)

