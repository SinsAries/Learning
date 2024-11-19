N = int(input())

cnt = [0] * (N + 1)
for i in range(2, N + 1):
    x = int(i)
    
    for j in range(2, int(x**0.5) + 1):
        if x % j == 0:
            while x % j == 0:
                cnt[j] += 1
                x //= j
    if(x > 1):
        cnt[x] += 1

res = 1
for i in range(2, N + 1):
    for j in range(cnt[i] - (cnt[i] % 2)):
        res = res * i
        res = res % 1000000007
print(res)