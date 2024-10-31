from Crypto.Util.number import long_to_bytes as ltb
from factordb.factordb import FactorDB
from math import ceil, sqrt
from gmpy2 import isqrt

f = open("./output.txt")
n = int(f.readline().split(' = ')[1])
e = int(f.readline().split(' = ')[1])
ct = int(f.readline().split(' = ')[1])

def is_not_square(x):
    if(x < 0):
        return True
    sqrt_num = isqrt(x)
    return sqrt_num * sqrt_num != x

a = isqrt(n)
b = a * a - n
while(is_not_square(b)):
    a = a + 1
    b = a * a - n
b = isqrt(b)

p = a - b
q = a + b
# print(p * q - n)
phi = (p - 1) * (q - 1)
d = pow(e, -1, phi)
print(ltb(pow(ct, d, n)).decode())