from hashlib import sha256
from random import choices
import collections

from Crypto.Cipher import AES
from Crypto.Util.Padding import pad

pt = bytes.fromhex('4145535f4145535f4145535f41455321')
ct = bytes.fromhex('edb43249be0d7a4620b9b876315eb430')
enc_flag = bytes.fromhex('e5218894e05e14eb7cc27dc2aeed10245bfa4426489125a55e82a3d81a15d18afd152d6c51a7024f05e15e1527afa84b')

chars = b'crew_AES*4=$!?'

res = {}

pt = b'AES_AES_AES_AES!'
for w1 in chars:
    for w2 in chars:
        for w3 in chars:
            for x1 in chars:
                for x2 in chars:
                    for x3 in chars:
                        w = bytes([w1]) + bytes([w2]) + bytes([w3])
                        x = bytes([x1]) + bytes([x2]) + bytes([x3])
                        k1 = sha256(w).digest()
                        k2 = sha256(x).digest()
                        ct1 = AES.new(k2, AES.MODE_ECB).encrypt(
                            AES.new(k1, AES.MODE_ECB).encrypt(
                                pt
                            )
                        )
                        res[ct1] = w + x
for y1 in chars:
    for y2 in chars:
        for y3 in chars:
            for z1 in chars:
                for z2 in chars:
                    for z3 in chars:
                        y = bytes([y1]) + bytes([y2]) + bytes([y3])
                        z = bytes([z1]) + bytes([z2]) + bytes([z3])
                        k3 = sha256(y).digest()
                        k4 = sha256(z).digest()
                        pt1 = AES.new(k3, AES.MODE_ECB).decrypt(
                            AES.new(k4, AES.MODE_ECB).decrypt(
                                ct
                            )
                        )
                        if pt1 in res:
                            print(res[pt1] + y + z)
                            key = sha256(res[pt1] + y + z).digest()
                            print(AES.new(key, AES.MODE_ECB).decrypt(enc_flag))