from Crypto.Util.number import long_to_bytes as ltb
from Crypto.Util.number import bytes_to_long as btl
def xor(x, y):
    return ltb(btl(x) ^ btl(y))

enc = bytes.fromhex('ed0d4de3936e2bd3e80d1725fde71ca1a2f2c4d912bc38e0fe295eb7bc88c582')
ptxt = b'00000000000000000000000000000000'
flag_enc = bytes.fromhex('a8491bbfc23960d5bb507873fda54ea0f6a6c7877db83fe7fa7a05d8bb8fc2cf')

print(xor(xor(enc, ptxt), flag_enc))

