n, q= map(int, input().split())
a = list(map(int, input().split()))
s = [0] * (n + 1)
for i in range(1, n+ 1):
    s[i] = s[i - 1] + a[i - 1]
for _ in range(q):
    u, v = map(int, input().split())
    u = u + 1
    v = v
    kq = s[v] - s[u - 1]
    print(kq)