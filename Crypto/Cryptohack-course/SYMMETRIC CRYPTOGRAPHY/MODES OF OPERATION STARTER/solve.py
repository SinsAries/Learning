import requests
import json

def get_encrypted_flag():
    url = "https://aes.cryptohack.org/block_cipher_starter/encrypt_flag/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

def get_decrypt(ciphertext):
    url = f"https://aes.cryptohack.org/block_cipher_starter/decrypt/{ciphertext}/"
    r = requests.get(url=url)

    plaintext = json.loads(r.text)["plaintext"]

    return plaintext

ciphertext = get_encrypted_flag()
print(bytes.fromhex(get_decrypt(ciphertext)).decode())