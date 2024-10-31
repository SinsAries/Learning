from pwn import *
import json
from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl

# # context.log_level = 'debug'
r = remote('socket.cryptohack.org', 13399, level = 'debug')

def change_password(new_password):
    return 'cac'

r.recvuntil(b'Please authenticate to this Domain Controller to proceed\n')
r.sendline(json.dumps({'option': 'reset_password', 'token': b'00000000000000000000000000000000'.hex()}))
r.recvuntil(b'{"msg": "Password has been correctly reset."}\n')
for i in range(256):
    token = ltb(i)*16
    password = token[:-4]
    password_length = btl(token[-4:])
    password = password[:password_length]
    
    try:
        decoded_password = password.decode()
    except UnicodeDecodeError:
        continue

    r.sendline(json.dumps({'option': 'authenticate', 'password': decoded_password}))
    rcv = r.recvuntil(b'\n')
    if(b'{"msg": "Welcome admin, flag: ' in rcv):
        print(rcv)
        break
       