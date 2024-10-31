import requests
import json
from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl

def get_encrypted(plaintext, iv):
    url = f"https://aes.cryptohack.org/symmetry/encrypt/{plaintext}/{iv}/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

def get_encrypted_flag():
    url = f"https://aes.cryptohack.org/symmetry/encrypt_flag/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

def xor(x, y):
    return ltb(btl(bytes.fromhex(x)) ^ btl(bytes.fromhex(y)))

enc_flag = get_encrypted_flag()
while(len(enc_flag) % 32):
    enc_flag += '0'
block_size = 32
blocks = [enc_flag[i * block_size : (i + 1) * block_size] for i in range(0, len(enc_flag)//block_size, 1)]
iv = blocks[0]

def cbc_enc(plaintext):
    return get_encrypted('00000000000000000000000000000000', plaintext)

flag = b''
for i in range(1, len(blocks), 1):
    iv = cbc_enc(iv)
    flag += xor(iv, blocks[i])

print(flag)