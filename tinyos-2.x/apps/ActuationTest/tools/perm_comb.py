def PermutationEnumerator(items, n=None):
    if n is None:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v
        else:
            rest = items[:i] + items[i+1:]
            for p in PermutationEnumerator(rest, n-1):
                yield v + p

def CombinationEnumerator(items, n=None):
    if n is None:
        n = len(items)
    for i in range(len(items)):
        v = items[i:i+1]
        if n == 1:
            yield v
        else:
            rest = items[i+1:]
            for c in CombinationEnumerator(rest, n-1):
                yield v + c

def __test1():
    items = [ 'a', 'b', 'c']
    for algo in (CombinationEnumerator, PermutationEnumerator):
        for selection in range(1, 4):
            print algo.__name__
            print items
            print selection
            enum = algo(items, selection)
            for i in enum:
                print i
            print "\n\n\n"

if __name__ == "__main__" : 
    __test1()

