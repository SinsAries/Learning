n = int(input())
a = list(map(int, input().split()))
vi_tri = [-1] * (n + 1)
for i in range(n):
    vi_tri[a[i]] = i

res = 1
for i in range(2, n + 1):
    if vi_tri[i] < vi_tri[i - 1]:
        res += 1

print(res)

