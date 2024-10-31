n, m = map(int, input().split())
x = list(map(int, input().split()))
p = [-1] * (n + 1)
for i in range(n):
    p[x[i]] = i + 1

res = 1
for i in range(2, n + 1):
    if p[i] < p[i - 1]:
        res += 1

for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1

    A = x[a]
    B = x[b]
    swap_pairs = {}
    if A + 1 <= n:
        swap_pairs[(A, A + 1)] = 1
    if A - 1 >= 1:
        swap_pairs[(A - 1, A)] = 1
    if B + 1 <= n:
        swap_pairs[(B, B + 1)] = 1
    if B - 1 >= 1:
        swap_pairs[(B - 1, B)] = 1

    for i in swap_pairs:
        res -= (p[i[0]] > p[i[1]])

    p[A], p[B] = p[B], p[A]
    x[a], x[b] = x[b], x[a]

    for i in swap_pairs:
        res += (p[i[0]] > p[i[1]])
    
    print(res)

