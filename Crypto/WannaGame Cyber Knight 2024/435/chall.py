from Crypto.Cipher import AES 
from Crypto.Util import Counter
from Crypto.Util.number import long_to_bytes as ltb, bytes_to_long as btl
from Crypto.Util.Padding import pad, unpad
import os



GREEN = '\033[92m'
RED = '\033[91m'
YELLOW = '\033[33m'
NORM = '\033[0m'


menu = \
f"""\
1. ECB_encrypt
2. CBC_decrypt
3. Crack Password
{"~"*100}
"""



class Riddle:
    def __init__(self, key, nonce):
        self.key = key
        self.nonce = nonce

    def GCM_encrypt(self, plaintext):
        """
        Return encryption of AES-GCM with provided plaintext
        """
        cipher_ = AES.new(self.key, AES.MODE_GCM, self.nonce)
        return cipher_.encrypt_and_digest(plaintext)

    def ECB_encrypt(self, plaintext):
        """
        Return encryption of AES-ECB with provided plaintext
        """
        cipher_ = AES.new(self.key, AES.MODE_ECB)
        return cipher_.encrypt(plaintext)

    def CBC_decrypt(self, iv, ciphertext):
        """
        Return decryption of AES-CBC with provided (ciphertext, iv)
        """
        cipher_ = AES.new(self.key, AES.MODE_CBC, iv)
        return cipher_.decrypt(ciphertext)

cipher = Riddle(key = os.urandom(16), nonce = os.urandom(12))


secret = os.urandom(256)
poem = \
pad(b"""\
The security code is simple, an intricate dance of numbers.
A shield against intruders, a fortress for slumbers.
Digits align in harmony, a secret melody they sing,
Guarding the treasures of a realm, where secrets take their wing : \
""", 16) + secret


ciphertext, tag = cipher.GCM_encrypt(poem)

print(f"ct = '{ciphertext.hex()}'")
print(f"tag = '{tag.hex()}'")
print(f"secret = '{secret.hex()}'")

while True:
    print(menu)
    option = int(input("Your choice > "))
    try:
        match option:
            case 1:
                m = bytes.fromhex(input("Please give me your message (in hex) > "))
                c = cipher.ECB_encrypt(m)
                print(c.hex())
            case 2:
                iv = bytes.fromhex(input("Please give me your iv (in hex) > "))
                c = bytes.fromhex(input("Please give me your ciphertext (in hex) > "))
                m = cipher.CBC_decrypt(iv, c)
                print(m.hex())
            case 3:
                key = bytes.fromhex(input("Give me your secret (in hex) > "))
                if key == secret:
                    FLAG = "Thanhdeptrai"
                    print(f"{GREEN}Wow you did surprise me!! Here is your reward {FLAG}")
                    exit()
                else:
                    print("Ahh, try better next time :(")
                    exit()
            case _:
                print("No idea what you choose :(")
    except Exception as e: 
        print(f"{RED}An exception occurred: {str(e)}")