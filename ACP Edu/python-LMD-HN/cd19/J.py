from sys import stdin, stdout
from math import gcd

f = stdin.readline().split()
if(len(f) == 1):
    x = int(f[0])
    y = int(stdin.readline()) 
else:
    x, y = map(int, f)
d = gcd(x, y)
x //= d
y //= d

stdout.write(f"{x * y}")