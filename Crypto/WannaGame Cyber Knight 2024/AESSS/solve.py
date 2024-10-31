from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl
from pwn import *
import json
from Crypto.Util import Counter
import os

# # context.log_level = 'debug'
r = remote('45.122.249.68', 20026, level = 'debug')

def xor(a, b):
    return ltb(btl(a) ^ btl(b))

r.recvuntil(b'challenge option:')
r.sendline('1'.encode())
r.recvuntil(b'> ')
r.sendline('cfb flag')
cfb_flag = r.recvuntil(b'\n').decode()[:-1]
r.recvuntil(b'> ')
r.sendline(('ecb data ' + cfb_flag[0:64]).encode())
ecb_cfb_flag = r.recvuntil(b'\n').decode()[:-1]
tmp = xor(bytes.fromhex(ecb_cfb_flag), bytes.fromhex(cfb_flag[32:96]))
r.recvuntil(b'> ')
r.sendline(('ofb data ' + '0'*32).encode())
ofb_data = r.recvuntil(b'\n').decode()[:-1]
flag_part_1 = xor(bytes.fromhex(ofb_data), bytes.fromhex(cfb_flag[:32])) + tmp
# print(flag_part_1)
# b'W1{AES_1s_w1d3ly_us3d_1n_r3al_w0rld_applic4t10ns'

# tmp0 = '81d6497e589e34b5a5c7ca82e1d0a78bbe404425a8d95673692328e9c090da3584f20fd422687067fea8b911d6e50131'
# tmp1 = 'dee2271a07af47eac6f7a4f1d0b494f98d241b5198863440361346da9fa0bc6af09a3c8b4f580313a1db8a72a397326e'
# flag_part_2 = xor(bytes.fromhex(tmp0), bytes.fromhex(tmp1))
flag_part_2 = b'_4nd_1s_c0ns1d3r3d_t0_b3_0n3_0f_th3_m0st_s3cur3_'

password = '7461796c6f72'
password = bytes.fromhex(password)
print(password.decode())
flag_part_3 = b'alg0r1thms_1n_pr4ct1c3_66e14a195cd4b2e9d5059ca1a'

flag = flag_part_1 + flag_part_2 + flag_part_3
tmp = '7461796c6f72'
print(bytes.fromhex(tmp))
print(flag.decode())
