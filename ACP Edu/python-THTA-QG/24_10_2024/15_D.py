n, k = map(int, input().split())
a = list(map(int, input().split()))
dpp = {}
res = 0
for i in a:
    if(i - k in dpp):
        res += dpp[i - k]
        
    if(k != 0 and i + k in dpp):
        res += dpp[i + k]

    if(i in dpp):
        dpp[i] += 1
    else:
        dpp[i] = 1        
print(res)
