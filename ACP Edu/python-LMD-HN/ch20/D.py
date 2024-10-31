N, V, H = map(int, input().split())

res = 0

for d1 in range(1, int(N**0.5) + 1):
    if(N % d1 == 0):
        if