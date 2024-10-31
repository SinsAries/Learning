from random import getrandbits
from Crypto.Util.number import long_to_bytes as ltb
from sage.all import *

def solve(n, cor_m, c, e):
    P = PolynomialRing(Zmod(n), 'x')
    f = P.gen() * P.gen() + 2 * cor_m * P.gen() - (c - pow(cor_m, e, n)) % n
    f = f.monic()
    print(f.small_roots(X = 2**256 + 1))

f = open('./out.txt')
n = int(f.readline().split(' = ')[1])
c = int(f.readline().split(' = ')[1])
e = 2
cor_m = int(f.readline().split(' = ')[1])

solve(n, cor_m, c, e)