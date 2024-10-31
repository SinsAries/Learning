n, x, q = map(int, input().split())
a = list(map(int, input().split()))
b = [(i < x) for i in a]
pref = [0]
for i in range(n):
    if(b[i]):
        pref.append(pref[-1] + 1)
    else:
        pref.append(pref[-1])

for _ in range(q):
    u, v = map(int, input().split())
    print(pref[v] - pref[u - 1])