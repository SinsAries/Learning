from pwn import *
import json
import itertools

def xor(key, data):
    return bytes([k ^ d for k, d in zip(itertools.cycle(key), data)])

# context.log_level = 'debug'
r = remote('challs.actf.co', 31398)
r.recvuntil(b'Pick 1, 2, or 3 > ')
r.send("2\n".encode())
r.recvuntil(b'Your message > ')
res = '00000000000000000000000000000000\n'
r.send(res.encode())
last_key = bytes.fromhex(r.recvline().decode()[:-1])

flag = bytes.fromhex('fb7fdbf9e714a08ce9cdf109bb527acba27accfeff16fcdcb1cdf358bb557898aa2d9da9af5c')

flag = xor(last_key, flag)
print(flag.decode())