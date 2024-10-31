import requests
import json
from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl

def get_cookie():
    url = "https://aes.cryptohack.org/flipping_cookie/get_cookie/"
    r = requests.get(url=url)

    cookie = json.loads(r.text)["cookie"]

    return cookie

def get_flag(cookie, iv):
    url = f"https://aes.cryptohack.org/flipping_cookie/check_admin/{cookie}/{iv}/"
    r = requests.get(url=url)

    flag = json.loads(r.text)["flag"]

    return flag

def xor(x, y):
    return ltb(btl(x) ^ btl(y))

cookie = get_cookie()
iv = bytes.fromhex(cookie[:32])
iv = xor(iv, xor(b'admin=False;expi', b'CAC;admin=True;C'))

flag = get_flag(cookie[32:], iv.hex())
print(flag)