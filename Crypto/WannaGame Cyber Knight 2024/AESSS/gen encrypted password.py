import os
import random
from Crypto.Cipher import AES
from Crypto.Util import Counter
from Crypto.Hash import SHA256
from Crypto.Util.number import long_to_bytes as ltb

def pad(data, block_size):
    return data + (block_size - len(data) % block_size) * bytes([block_size - len(data) % block_size])

password_file_path = './rockyou.txt'
with open(password_file_path, "rb") as file:
    passwords = file.readlines()[:100]

f = open('./tmp.txt', 'w')

for a in range(256):
    for b in range(256):
        salt = ltb(a) + ltb(b)
        for password in passwords:
            password = password.strip()
            key = SHA256.new(password + salt.hex().encode()).digest()[:16]
            cipher = AES.new(key, AES.MODE_ECB)
            ciphertext = cipher.encrypt(pad(password, 16))
            f.write(password.hex() + ' -> ' + ciphertext.hex() + '\n')