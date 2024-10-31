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

tmp = r.recvuntil(b')\n').decode()[16:-2].split(', ')
x = int(tmp[0])
y = int(tmp[1])


pk1 = fastecdsa.point.Point(x, y, curve=curve)
tmp = myPK - pk1
r.recvuntil(b'x: ')
r.sendline(str(tmp.x).encode())
r.recvuntil(b'y: ')
r.sendline(str(tmp.y).encode())

r.recvuntil(b'message: ')
r.sendline('00'.encode())

myK, myR = fastecdsa.keys.gen_keypair(curve)
tmp = r.recvuntil(b')\n').decode()[11:-2].split(', ')
x = int(tmp[0])
y = int(tmp[1])
R1 = fastecdsa.point.Point(x, y, curve = curve)
tmp = myR - R1
# print(tmp.x)
# print(tmp.y)
r.recvuntil(b'x: ')
r.sendline(str(tmp.x).encode())
r.recvuntil(b'y: ')
r.sendline(str(tmp.y).encode())

tmp = myPK - pk1

# print("c ")

c = hash_transcript(myPK, myR, b'flag')
s = (myK - c * mySK) % curve.q
r.recvuntil(b'c: ')
r.sendline(str(c).encode())
r.recvuntil(b's: ')
r.sendline(str(s).encode())
print(r.recvall().decode()[:-1])
