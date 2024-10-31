N = int(input())

res = ''
numOfDivisors = 1

p = 2

while (N > 0):
    if N % p == 0:
        count = 0
        while N % p == 0:
            N //= p
            count += 1
            res += str(p) + '*'
        numOfDivisors *= (count + 1)
    p += 1
    if(p > int(N**0.5)):
        break

if(N > 1):
    res += str(N) + '*'
    numOfDivisors *= 2

print(res[:-1])
print(numOfDivisors)