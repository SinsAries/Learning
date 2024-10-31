from sys import stdin, stdout

n, k = map(int, stdin.readline().strip().split())
a = []
i = 0
cnt = [0] * 21
res = 0
for j in range(n):
    a.append(len(stdin.readline().strip()))

    while j - i > k:
        cnt[a[i]] -= 1
        i += 1

    res += cnt[a[j]]
    cnt[a[j]] += 1

stdout.write(str(res))

    