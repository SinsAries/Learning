from Crypto.Util.number import bytes_to_long as btl
from Crypto.Util.number import long_to_bytes as ltb
from sage.all import *
import owiener

f = open('./output.txt')
n = btl(bytes.fromhex(f.readline().split(' = ')[1][2:]))
e = btl(bytes.fromhex(f.readline().split(' = ')[1][2:]))
c = btl(bytes.fromhex(f.readline().split(' = ')[1][2:]))
d = owiener.attack(e, n)

print(ltb(pow(c, d, n)).decode())