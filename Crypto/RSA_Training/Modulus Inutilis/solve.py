from Crypto.Util.number import long_to_bytes as ltb

f = open("./output.txt")
n = int(f.readline().split(' = ')[1])
e = int(f.readline().split(' = ')[1])
ct = int(f.readline().split(' = ')[1])

l = 0
r = n + 1
while(l + 1 < r):
    m = l + (r - l + 1) // 2
    if(m * m * m == ct):
        ct = m
    if(m * m * m > ct):
        r = m
    else:
        l = m

print(ltb(ct).decode())