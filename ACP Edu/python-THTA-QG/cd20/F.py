from math import gcd

a = int(input())
b = int(input())
c = int(input())

cnt = {}

def calc(x):
    i = 2
    while i * i <= x:
        if x % i == 0:
            if i not in cnt:
                cnt[i] = 0
            while x % i == 0:
                cnt[i] += 1
                x //= i
        i += 1
    if x > 1:
        if x not in cnt:
            cnt[x] = 0
        cnt[x] += 1

calc(a)
calc(b)
calc(c)

d = 0
for key, val in cnt.items():
    d = gcd(d, val)
print(d)