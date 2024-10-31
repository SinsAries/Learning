from pwn import *
import json

r = remote('challenge.nahamcon.com', 30392, level = 'debug')

r.recvuntil(b'>> ')
r.send("50\n".encode())

for i in range(70):
    r.recvuntil(b'>> ')
    r.send((str(i + 1) + '\n').encode())
    r.recvuntil(b'>> ')
    r.send((str(i + 1) + '\n').encode())
    r.recvuntil(b'>> ')
    r.send((str(i + 1) + '\n').encode())
for i in range(30):
    r.recvuntil(b'>> ')
    r.send((str(i + 1) + '\n').encode())
    r.recvuntil(b'>> ')
    r.send((str(i + 1) + '\n').encode())
    r.recvuntil(b'>> ')
    r.send((str(i + 1) + '\n').encode())

r.recvall()