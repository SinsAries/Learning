from pwn import *
import json
from Crypto.Util.Padding import pad, unpad
from Crypto.Util.number import long_to_bytes as ltb, bytes_to_long as btl

def xor(x, y):
    return bytes([a ^ b for a, b in zip(x, y)])

context.log_level = 'debug'
r = process(["python3", "chall.py"])

r.interactive()

secret = os.urandom(256)
poem = \
pad(b"""\
The security code is simple, an intricate dance of numbers.
A shield against intruders, a fortress for slumbers.
Digits align in harmony, a secret melody they sing,
Guarding the treasures of a realm, where secrets take their wing : \
""", 16) + secret

r.recvuntil(b'ct = ')
ct = r.recvuntil(b'\n').decode()[1:-2]
tag = r.recvuntil(b'\n').decode()[:-1].split(' = ')[1][1:-1]

tmp = xor(bytes.fromhex(ct[:32]), bytes.fromhex(poem.hex()[:32]))

r.recvuntil(b'Your choice > ')
r.sendline('2'.encode())
r.recvuntil(b'Please give me your iv (in hex) > ')
r.sendline(('0'*32).encode())
r.recvuntil(b'Please give me your ciphertext (in hex) > ')
r.sendline(tmp.hex().encode())
counter1 = r.recvuntil(b'\n').decode()[:-1]
counter = b''
for i in range(15, 31, 1):
    counter += ltb(btl(bytes.fromhex(counter1)) + i)
counter = counter.hex()
print(counter)

r.recvuntil(b'Your choice > ')
r.sendline('1'.encode())
r.recvuntil(b'Please give me your message (in hex) > ')
r.sendline(counter.encode())
counter = r.recvuntil(b'\n').decode()[:-1]
blocks = [counter[i:i+32] for i in range(0, len(counter), 32)]
print(blocks)

secret_enc = ct[(len(ct) // 32 - 512 // 32) * 32:]
print(f"secret_enc = '{secret_enc}'")
secret = xor(bytes.fromhex(counter), bytes.fromhex(secret_enc)).hex()
print(secret)

r.recvuntil(b'Your choice > ')
r.sendline('3'.encode())
r.recvuntil(b'Give me your secret (in hex) > ')
r.sendline(secret.encode())
r.interactive()