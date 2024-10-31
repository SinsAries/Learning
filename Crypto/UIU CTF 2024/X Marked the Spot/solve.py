from Crypto.Util.number import long_to_bytes as ltb, bytes_to_long as btl
f = open("./ct", "rb").read()
known_plaintext = b'uiuctf{'
key = b''
for i in range(7):
    key += ltb(f[i] ^ known_plaintext[i])
key += ltb(f[47] ^ ord('}'))
flag = b''
for i in range(len(f)):
    flag += ltb(f[i] ^ key[i % 8])
print(flag.decode())