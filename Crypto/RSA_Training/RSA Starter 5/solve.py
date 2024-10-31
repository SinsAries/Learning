from factordb.factordb import FactorDB

N = 882564595536224140639625987659416029426239230804614613279163
e = 65537
c = 77578995801157823671636298847186723593814843845525223303932

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

# uses his private key (N,d) to compute m = c^d mod N
plain = pow( c, d, N )

print(plain)