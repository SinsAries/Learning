N = int(input())
 
p = 2
while (N > 1):
    if N % p == 0:
        count = 0
        while N % p == 0:
            N //= p
            count += 1
        print(p, count)
    p += 1
    if(p * p > N):
        break
if(N > 1):
    print(N, 1)