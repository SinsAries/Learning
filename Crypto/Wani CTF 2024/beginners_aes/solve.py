from Crypto.Util.number import long_to_bytes as ltb, bytes_to_long as btl
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad
import hashlib

for KEY in range(256):
    for IV in range(256):
        key = b'the_enc_key_is_'
        iv = b'my_great_iv_is_'
        key += ltb(KEY)
        iv += ltb(IV)

        cipher = AES.new(key, AES.MODE_CBC, iv)
        enc_FLAG = b'\x16\x97,\xa7\xfb_\xf3\x15.\x87jKRaF&"\xb6\xc4x\xf4.K\xd77j\xe5MLI_y\xd96\xf1$\xc5\xa3\x03\x990Q^\xc0\x17M2\x18'
        FLAG = cipher.decrypt(enc_FLAG)

        if b'FLAG' in FLAG:
            targetHash = '6a96111d69e015a07e96dcd141d31e7fc81c4420dbbef75aef5201809093210e'
            for i in range(len(FLAG)):
                flag = FLAG[:-i]
                flag_hash = hashlib.sha256(flag).hexdigest()
                if(flag_hash == targetHash):
                    print(flag)
                    exit()