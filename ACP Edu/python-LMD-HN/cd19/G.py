from sys import stdin, stdout
from math import gcd

n = int(stdin.readline())
a = list(map(int, stdin.readline().split(' ')))

res = a[0]
for i in range(1, n):
    res = res * a[i] // gcd(res, a[i])

stdout.write(str(res))