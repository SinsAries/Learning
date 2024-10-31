n, k = map(int, input().split())
a = list(map(int, input().split()))

res = 1000001

last_pos = [-1] * (1000001)
idx = 1
for i in a:
    if last_pos[i] != -1 and last_pos[i] + k > idx:
        res = min(res, i)
    last_pos[i] = idx
    idx += 1
if(res == 1000001):
    print(-1)
else:
    print(res)