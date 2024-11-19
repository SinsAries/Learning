from math import *
so = list(map(int,input().split()))
if len(so) == 1:
    b = int(input())
    print(gcd(so[0],b),lcm(so[0],b))
else:
    print(gcd(so[0],so[1]),lcm(so[0],so[1]))

gcd(0, a1) = a1
gcd(0, a1, a2) = gcd(gcd(0, a1), a2)
gcd(0, a1, a2, a3) = gcd(gcd(0, a1, a2), a3) = gcd(gcd(gcd(0, a1), a2), a3)