from math import lcm
n = int(input())

res = n

for a in range(1, int(n ** 0.5) + 1):
    if n % a == 0:
        fake_b = n // a
        if(lcm(a, fake_b) == n): # b is real    
            res = min(res, fake_b)

print(n // res, res)
