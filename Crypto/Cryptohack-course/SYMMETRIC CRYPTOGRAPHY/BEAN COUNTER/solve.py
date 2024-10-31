import requests
import json

def get_encrypted():
    url = f"https://aes.cryptohack.org/bean_counter/encrypt/"
    r = requests.get(url=url)

    cipher_text = json.loads(r.text)["encrypted"]

    return cipher_text

enc = get_encrypted()

block_size = 32
blocks = [enc[i * block_size : (i + 1) * block_size] for i in range(0, len(enc)//block_size, 1)]
png_header = '89504e470d0a1a0a0000000d49484452'
# print(len(png_header))
key = bytes([a^b for a, b in zip(bytes.fromhex(blocks[0]), bytes.fromhex(png_header))])
flag = b''
for i in range(0, len(blocks), 1):
    flag += bytes([a^b for a, b in zip(bytes.fromhex(blocks[i]), key)])

open("./flag.png", 'wb').write(flag)