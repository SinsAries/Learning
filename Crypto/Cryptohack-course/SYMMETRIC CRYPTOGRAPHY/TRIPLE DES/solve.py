
def xor(a, b):
    # xor 2 bytestrings, repeating the 2nd one if necessary
    return bytes(x ^ y for x,y in zip(a, b * (1 + len(a) // len(b))))

a = 'aaaaaaaaaaaaaaaa'
ab = 'aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb'
a = bytes.fromhex(a)
ab = bytes.fromhex(ab)

c = xor(ab, a)
print(c.hex())

print(xor(bytes.fromhex('aa'), bytes.fromhex('bb')).hex())