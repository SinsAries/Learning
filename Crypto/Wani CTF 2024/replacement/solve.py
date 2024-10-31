import hashlib
trans_from_hash_to_char = {}

for i in range(256):
    x = hashlib.md5(str(i).encode()).hexdigest()
    x = int(x, 16)
    trans_from_hash_to_char[x] = chr(i)

with open('my_diary_11_8_Wednesday.txt', 'r') as f:
    enc = eval(f.read())
    
res = ''
for i in enc:
    res += trans_from_hash_to_char[i]
print(res)