from Crypto.Util.number import long_to_bytes as ltb

f = open("./output.txt")

'''
    read input from output.txt
'''
N = int(f.readline().split(' = ')[1][:-1])
e = int(f.readline().split(' = ')[1][:-1])
ct = int(f.readline().split(' = ')[1])

'''
    get private key
'''
p = 1
l = 1
r = N
while(l + 1 < r):
    m = l + (r - l + 1) // 2
    if(m * m == N):
        p = m
        break
    if(m * m < N):
        l = m
    else:
        r = m
phi = p * (p - 1)
d = pow(e, -1, phi)


'''
    decrypt ciphertext
'''
print(ltb(pow(ct, d, N)).decode())