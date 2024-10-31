import requests
import json
from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl

def encrypt(plaintext):
    url = f"https://aes.cryptohack.org/lazy_cbc/encrypt/{plaintext}/"
    r = requests.get(url=url)

    cookie = json.loads(r.text)["ciphertext"]

    return cookie

def get_flag(key):
    url = f"https://aes.cryptohack.org/lazy_cbc/get_flag/{key}/"
    r = requests.get(url=url)

    flag = json.loads(r.text)["plaintext"]

    return flag

def decrypt(ciphertext):
    url = f"https://aes.cryptohack.org/lazy_cbc/receive/{ciphertext}"
    r = requests.get(url=url)

    plaintext = json.loads(r.text)['error']

    return plaintext

tmp = encrypt(b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'.hex())
tmp = encrypt(b'\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'.hex() + tmp)
key = decrypt(tmp[32:64]).split(' ')[2]
print(bytes.fromhex(get_flag(key)).decode())
