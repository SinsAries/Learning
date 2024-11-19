from math import gcd,lcm
n = int(input())
a = {}

def getGCD():
    kq = 1
    for i in a:
        kq = gcd(kq, i)
    if(kq == 1):
        return -1
    return kq

for _ in range(n):
    t, x = list(map(int,input().split()))
    if t == 1:
        if(x in a):
            a[x] += 1
        else:
            a[x] = 1    
    else:
        a[x] -= 1
        if a[x] == 0:
            del a[x]

    print(getGCD())
