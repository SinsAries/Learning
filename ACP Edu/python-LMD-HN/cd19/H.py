from math import gcd, sqrt, floor

n = int(input())

resB = n

for a in range(1, floor(sqrt(n)) + 1):
    if n % a == 0:
        b = n // a
        if(gcd(a, b) == 1):
            resB = min(resB, b)

resA = n // resB

print(resA, resB)

