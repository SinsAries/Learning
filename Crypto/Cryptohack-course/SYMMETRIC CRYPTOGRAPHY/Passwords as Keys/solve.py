from Crypto.Cipher import AES
import hashlib
import random

import requests
import json

def get_encrypted_flag():
    url = "https://aes.cryptohack.org/passwords_as_keys/encrypt_flag/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

def get_decrypt(ciphertext, password_hash):
    url = f"https://aes.cryptohack.org/passwords_as_keys/decrypt/{ciphertext}/{password_hash}/"
    r = requests.get(url=url)

    plaintext = json.loads(r.text)["plaintext"]

    return plaintext

# /usr/share/dict/words from
# https://gist.githubusercontent.com/wchargin/8927565/raw/d9783627c731268fb2935a731a618aa8e95cf465/words
with open("./words.txt") as f:
    words = [w.strip() for w in f.readlines()]

ENCRYPTED_FLAG = get_encrypted_flag()

def brute_force():
    for word in words:
        key = hashlib.md5(word.encode()).digest()
        decrypted = get_decrypt(ENCRYPTED_FLAG, key.hex())
        print(str(bytes.fromhex(decrypted)))
        if "crypto" in str(bytes.fromhex(decrypted)):
            return decrypted

    return None

print(brute_force())