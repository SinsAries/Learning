from hashlib import sha256
import fastecdsa.curve
import fastecdsa.keys
import fastecdsa.point
from sage.all import *
from pwn import *
import json

def hash_transcript(pk, R, msg):
	h = sha256()
	h.update(f'({pk.x},{pk.y})'.encode())
	h.update(f'({R.x},{R.y})'.encode())
	h.update(msg)
	return int.from_bytes(h.digest(), 'big') % curve.q

curve = fastecdsa.curve.secp256k1


mySK, myPK = fastecdsa.keys.gen_keypair(curve)

# # context.log_level = 'debug'
r = remote('challs.actf.co', 31301, level = 'debug')

r.recvall()

x = int(input())
y = int(input())

pk1 = fastecdsa.point.Point(x, y, curve=curve)
tmp = myPK - pk1
print("tmp")
print(tmp.x)
print(tmp.y)

myK, myR = fastecdsa.keys.gen_keypair(curve)

x = int(input())
y = int(input())

R1 = fastecdsa.point.Point(x, y, curve = curve)
tmp = myR - R1
tmp = myPK - pk1
print(tmp.x)
print(tmp.y)

print("c ")

c = hash_transcript(myPK, myR, b'flag')
s = (myK - c * mySK) % curve.q
print(c)
print(s)
