from sys import stdin, stdout
from math import gcd

m, n = map(int, stdin.readline().split(' '))
d = gcd(m, n)
res = f"{m // d}/{n // d}"

stdout.write(res)