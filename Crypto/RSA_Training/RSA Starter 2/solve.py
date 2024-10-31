p = 17
q = 23
N = p * q
e = 65537

m = 12
c = pow(m, e, N)
print(c)