from factordb.factordb import FactorDB
from Crypto.Util.number import long_to_bytes as ltb

f = open("./output.txt")

'''
    read input from output.txt
'''
N = int(f.readline().split(' = ')[1][:-1])
e = int(f.readline().split(' = ')[1][:-1])
ct = int(f.readline().split(' = ')[1][:-1])

'''
    get private key
'''
factors = FactorDB(N)
factors.connect()
factors = factors.get_factor_list()
check = {-1}
phi = 1
for num in factors:
    if(num in check):
        phi *= num
    else:
        phi *= num - 1
        check.add(num)
d = pow(e, -1, phi)


'''
    decrypt ciphertext
'''
print(ltb(pow(ct, d, N)).decode())