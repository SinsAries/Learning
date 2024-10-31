n, k = map(int, input().split())
S = input()

i = 0
dpp = {}
res = 0
while i + k - 1 < n:
    tmp = S[i:i + k]
    if tmp in dpp:
        i += 1
        continue
    dpp[tmp] = 1
    res += 1
    i += 1
print(res)