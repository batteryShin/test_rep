import sys

class Pair:
    def __init__(self,val1,val2):
        self.a = val1
        self.b = val2
        pass

    a = -1
    b = -1
    pass


cases = sys.stdin.readline()
for c in range(int(cases)):
    line = sys.stdin.readline()
    nnumber,npairs = line.split()

    line = sys.stdin.readline()
    pairs = line.split()

    plist = []
    for p in range(int(npairs)):
        plist.append(Pair(pairs[2*p],pairs[2*p+1]))

        
    for p in plist:
        print p.a + "," + p.b

    print

