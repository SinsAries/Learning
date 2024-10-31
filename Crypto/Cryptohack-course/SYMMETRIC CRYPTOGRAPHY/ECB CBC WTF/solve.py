from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl
import requests
import json


def get_encrypted_flag():
    url = "https://aes.cryptohack.org/ecbcbcwtf/encrypt_flag/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

def get_decrypt(ciphertext):
    url = f"https://aes.cryptohack.org/ecbcbcwtf/decrypt/{ciphertext}/"
    r = requests.get(url=url)

    plaintext = json.loads(r.text)["plaintext"]

    return plaintext

cipher_text = get_encrypted_flag()

iv = cipher_text[:32]
block1 = cipher_text[32:64]
block2 = cipher_text[64:]

block1_decrypt = get_decrypt(block1)
block2_decrypt = get_decrypt(block2)

def xor(x, y):
    return ltb(btl(x) ^ btl(y))

first_part_of_flag = xor(bytes.fromhex(iv), bytes.fromhex(block1_decrypt))
second_part_of_flag = xor(bytes.fromhex(block1), bytes.fromhex(block2_decrypt))
print(str(first_part_of_flag.decode()) + str(second_part_of_flag.decode()))
