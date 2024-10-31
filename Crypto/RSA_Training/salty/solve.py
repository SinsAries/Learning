from Crypto.Util.number import long_to_bytes as ltb

f = open("./output.txt")
n = f.readline().split(' = ')[1]
e = f.readline().split(' = ')[1]
ct = f.readline().split(' = ')[1]
print(ltb(int(ct)).decode())