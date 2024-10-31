from pwn import *
from utils import *
import json

r = remote('ctf2024-entry.r3kapig.com', 32468, level='debug')

AliceUsername = b'AliceIsSomeBody'
BobUsername = b'BobCanBeAnyBody'

r.recvuntil(b'Now input your option: ')
r.sendline('3'.encode())
r.recvuntil(b'Username[HEX]: ')
r.sendline('0000000000000000'.encode())
r.recvuntil(b'Password[HEX]: ')
r.sendline('0000000000000000'.encode())

r.recvuntil(b'Now input your option: ')
r.sendline('1'.encode())
r.recvuntil(b'Username[HEX]: ')
r.sendline('0000000000000000'.encode())
r.recvuntil(b'Password[HEX]: ')
r.sendline('0000000000000000'.encode())

r.recvuntil(b'Hello ')
r.sendline('1'.encode())
r.recvuntil(b'Username[HEX]: ')
r.sendline(AliceUsername.hex().encode())
r.recvuntil(b'New Password[HEX]: ')
r.sendline('0000000000000000'.encode())
r.recvuntil(b'Hello ')
r.sendline('1'.encode())
r.recvuntil(b'Username[HEX]: ')
r.sendline(BobUsername.hex().encode())
r.recvuntil(b'New Password[HEX]: ')
r.sendline('0000000000000000'.encode())
r.recvuntil(b'Hello ')
r.sendline('5'.encode())

r.recvuntil(b'Now input your option: ')
r.sendline('1'.encode())
r.recvuntil(b'Username[HEX]: ')
r.sendline(AliceUsername.hex().encode())
r.recvuntil(b'Password[HEX]: ')
r.sendline('0000000000000000'.encode())
r.recvuntil(b'Hello ')
r.sendline('4'.encode())
r.recvuntil(b'Your private key is:')
Alice_private_key = r.recvuntil(b'\n').decode()[:-1]
r.recvuntil(b'Your public key is:')
Alice_public_key = r.recvuntil(b'\n').decode()[:-1]
r.recvuntil(b'Hello AliceIsSomeBody,do you need any services? ')
r.sendline('5'.encode())

r.recvuntil(b'Now input your option: ')
r.sendline('1'.encode())
r.recvuntil(b'Username[HEX]: ')
r.sendline(BobUsername.hex().encode())
r.recvuntil(b'Password[HEX]: ')
r.sendline('0000000000000000'.encode())
r.recvuntil(b'Hello ')
r.sendline('4'.encode())
r.recvuntil(b'Your private key is:')
Bob_private_key = r.recvuntil(b'\n').decode()[:-1]
r.recvuntil(b'Your public key is:')
Bob_public_key = r.recvuntil(b'\n').decode()[:-1]
r.recvuntil(b'Hello BobCanBeAnyBody,do you need any services? ')
r.sendline('3'.encode())
r.recvuntil(b'[AliceIsSomeBody] to [BobCanBeAnyBody]: Now its my encrypted flag:\n[AliceIsSomeBody] to [BobCanBeAnyBody]: ')
flag = r.recvuntil(b'\n').decode()[:-1]

print(f'Alice private key: {Alice_private_key}')
print(f'Alice public key: {Alice_public_key}')
print(f'Bob private key: {Bob_private_key}')
print(f'Bob public key: {Bob_public_key}')

# r.recvall();