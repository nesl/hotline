
import sys
import random

# Adapted from
# http://code.activestate.com/recipes/156453-choose-a-random-k-subset-of-12-n/
def ranksb1(n,k):
    if k > n: raise Exception, "N must be no less than K"
    if k > n * 2 // 3:
        pool = range(n)
        for i in xrange(n-1, n-k-1, -1):
            j = random.randrange(i+1)
            pool[i], pool[j] = pool[j], pool[i]
        return pool[-k:]
    selections = {}
    while k > len(selections):
        value = random.randrange(1, n+1)
        if value-1 in selections:
            continue
        selections[value-1] = True
    return selections.keys()

