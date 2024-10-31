from sys import stdin, stdout
import math

N, p = map(int, stdin.readline().split(' '))
if(N % p != 0):
    stdout.write(str(0))
else:
    res = 0
    for i in range(p, N + 1, p):
        if(math.gcd(N, i) == p):
            res += 1
    stdout.write(str(res))