from pwn import *
import json
from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl

# # context.log_level = 'debug'
r = remote('3.38.106.210', 8287, level = 'debug')

p = r.recvuntil(b'p_mask : ').split(b'\n')[-2].split(b' : ')[-1].decode()[2:]
if(len(p) % 2 != 0):
    p = '0' + p
p_hex = p
p = bin(btl(bytes.fromhex(p)))[2:]

p_mask = r.recvuntil(b'q : ').split(b'\n')[-2].decode()[2:]
if(len(p_mask) % 2 != 0):
    p_mask = '0' + p_mask
p_mask_hex = p_mask
p_mask = bin(btl(bytes.fromhex(p_mask)))[2:]

q = r.recvuntil(b'q_mask : ').split(b'\n')[-2].decode()[2:]
if(len(q) % 2 != 0):
    q = '0' + q
q_hex = q
q = bin(btl(bytes.fromhex(q)))[2:]

q_mask = r.recvuntil(b'N : ').split(b'\n')[-2].decode()[2:]
if(len(q_mask) % 2 != 0):
    q_mask = '0' + q_mask
q_mask_hex = q_mask
q_mask = bin(btl(bytes.fromhex(q_mask)))[2:]

N = r.recvuntil(b'input p in hex format : ').split(b'\n')[-2].decode()[2:]
if(len(N) % 2 != 0):
    N = '0' + N
N_hex = N
N = bin(btl(bytes.fromhex(N)))[2:]

print(p_hex)
print(p_mask_hex)
print(q_hex)
print(q_mask_hex)
print(N_hex)

print(f'p : {p}')
print(f'p_mask : {p_mask}')
print(f'q : {q}')
print(f'q_mask : {q_mask}')
print(f'N : {N}')

r.recvall()