from sage.all import *
from pwn import *
import json

def solve(n, c):
    c = c * c % n
    P = PolynomialRing(Zmod(n), 'x')
    f = P.gen() * P.gen() - c
    f = f.monic()
    print(f.small_roots(X = 2**128 + 1))
    return str(hex(min(f.small_roots(X = 2**128 + 1))))[2:]

n = 145639951148525675070822028220794029118957986080344496288964763562410055937004225551939934175076233805127214409964002269826253759338126214282919422425668077794601681795280990696048661372157157711792665120376947005262027516931144420311496429147356392858638060763340137461646854703792147534558717960193088808077
c = 265470299464165039068752578224375855466
print(solve(n, c))