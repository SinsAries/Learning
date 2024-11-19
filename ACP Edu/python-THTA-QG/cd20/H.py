from sys import stdin

n = int(stdin.readline().strip())
a = list(map(int, stdin.readline().strip().split()))
cnt = [0] * n

for idx in range(n):
    val = a[idx]
    i = 2

    while(i * i <= val):
        if val % i == 0:
            while val % i == 0:
                cnt[idx] += 1
                val //= i
        i += 1

    if val > 1:
        cnt[idx] += 1

print(sum(cnt) - max(cnt))