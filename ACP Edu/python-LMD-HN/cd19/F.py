from sys import stdin, stdout
from math import gcd
from collections import Counter

N = int(stdin.readline())
f = Counter()

def getGCD():
    if(len(f) == 0):
        return 1
    res = 0
    for element, count in f.items():
        res = gcd(res, element)
    return res

for _ in range(N):
    t, x = map(int, stdin.readline().split(' '))
    if(t == 1):
        f.update([x])
    else:
        f.subtract([x])
        if(f[x] == 0):
            del f[x]
    
    stdout.write(str(getGCD()) + '\n')