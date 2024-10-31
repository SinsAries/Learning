import zlib

flag = b'Crypto{ThanhDepTrai}'
input = b'Crypto{'
compressed_flag = zlib.compress(flag)
compressed_input = zlib.compress(input + input + input)
compressed_input_flag = zlib.compress(input + flag)

print(compressed_flag)
print(compressed_input)
print(compressed_input_flag)
print()
print(len(compressed_flag))
print(len(compressed_input))
print(len(compressed_input_flag))