import requests
import json
from Crypto.Util.number import bytes_to_long as btl
from Crypto.Util.number import long_to_bytes as ltb
import sys

def get_encrypted_flag():
    url = "https://aes.cryptohack.org/stream_consciousness/encrypt/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

ciphertexts = []
if len(sys.argv) == 2 and sys.argv[1] == 'setup':
    for i in range(100):
        encrypted = get_encrypted_flag()
        ciphertexts.append(encrypted)
    unique_elements = set(ciphertexts) 
    f = open('encrypted.txt', 'w') 
    for element in unique_elements: 
        f.write(element + '\n') 
    f.close()
else:
    f = open('encrypted.txt', 'r')
    ciphertexts = f.readlines()
    f.close()

ciphertexts = [bytes.fromhex(x[:200]) for x in ciphertexts]
def xor(a, b):
    return bytes([x^y for x, y in zip(a, b)])
know_plaintext = b'crypto{' + xor(b'\x1f', b't') + xor(b'W', b'd') + xor(b'Y', b' ') + xor(b'Y', b'l') + xor(b'e', b'R') + xor(b'\x1e', b'l') + xor(b'\x13', b' ') + xor(b'\x14', b' ') + xor(b'\x06', b'k')
know_plaintext += xor(b'1', b'n') + xor(b'\x15', b'g') + xor(b'J', b'y') + xor(b'\x1d', b'h') + xor(b'F', b's') + xor(b']', b'n') + xor(b'8', b'g') + xor(b'\x11', b' ')
know_plaintext += xor(b'A', b't') + xor(b'1', b'n') + xor(b'\x01', b'g') + xor(b'ZP\x14', b'ng ') + xor(b'\x05\x13', b'in')
know_plaintext += b'\x00' * (50 - len(know_plaintext.decode()))

key = xor(ciphertexts[14], know_plaintext)


for text in ciphertexts:
    print(xor(text, key))
        
