import requests
import json
import zlib
from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl

def get_encrypted(plaintext):
    url = f"https://aes.cryptohack.org/ctrime/encrypt/{plaintext}/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["ciphertext"]

    return cipher_text

a = b'crypto{'
print(a.hex())
l = len(get_encrypted(a.hex()))
# print(l)

flag = b'crypto{CRIME_571ll_p4y5}'
print(flag.hex())
l = len(get_encrypted(flag.hex()))
# print(l)

tmp = b'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_{}!?'
while(True):
    ok = False
    for c in tmp:
        b = a + ltb(c)
        print(b)
        if len(get_encrypted(b.hex())) == l:
            a = b
            ok = True
            break
    l = len(get_encrypted(a.hex()))
    if not ok:
        break
    print(a)
print(a)