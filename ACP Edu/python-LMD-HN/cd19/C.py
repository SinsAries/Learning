from sys import stdin, stdout
from math import gcd

a, b = map(int, stdin.readline().split(' '))
d = gcd(a, b)

res = 1

def getSumDigit(x):
    if(x == 0):
        return 0
    return x % 10 + getSumDigit(x // 10)

for i in range(1, d + 1):
    if(i * i > d):
        break
    if(d % i == 0):
        res = max(res, getSumDigit(i))
        if(d // i != i):
            res = max(res, getSumDigit(d // i))

stdout.write(str(res))