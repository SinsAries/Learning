from sys import stdin, stdout
from math import gcd

n = int(stdin.readline())
a = list(map(int, stdin.readline().split(' ')))

res = 0
for i in range(n):
    res = gcd(res, a[i])

stdout.write(str(res))