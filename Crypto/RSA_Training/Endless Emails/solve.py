from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import GCD
from sage.all import *

f = open("./output.txt")

n = []
c = []
def root3(x):
    l = 0
    r = x + 1
    while(l + 1 < r):
        m = l + (r - l + 1) // 2
        if(m * m * m == x):
            return m
        if(m * m * m > x):
            r = m
        else:
            l = m
    return -1

for i in range(7):
    n.append(int(f.readline().split(' = ')[1]))
    e = int(f.readline().split(' = ')[1])
    c.append(int(f.readline().split(' = ')[1]))
    f.readline()
    f.readline()

for i in range(7):
    for j in range(i + 1, 7, 1):
        for k in range(j + 1, 7, 1):
            v = [c[i], c[j], c[k]]
            m = [n[i], n[j], n[k]]
            x = CRT_list(v, m)
            if(root3(x) != -1):
                print(ltb(root3(x)).decode())