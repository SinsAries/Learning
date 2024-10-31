from math import gcd
from sys import stdin, stdout

f = stdin.readline().split()
if(len(f) == 1):
    a = int(f[0])
    b = int(stdin.readline()) 
else:
    a, b = map(int, f)

d = gcd(a, b)
lcm = a // d * b
res = f"{d} {lcm}"

stdout.write(res)
