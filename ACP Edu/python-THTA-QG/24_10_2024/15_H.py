n, k = map(int, input().split())
a = list(map(int, input().split()))

pref = [0]
for i in a:
    pref.append(pref[-1] + i)

dpp = {}
res = 0
for j in range(n + 1):
    if (pref[j] - k) in dpp:
        res += dpp[pref[j] - k]
    
    if pref[j] in dpp:
        dpp[pref[j]] += 1
    else:
        dpp[pref[j]] = 1

print(res)