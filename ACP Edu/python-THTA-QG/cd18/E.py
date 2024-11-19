from sys import stdin, stdout

m,n = list(map(int,stdin.readline().strip().split()))

th = [0]*m
tc = [0]*n
mang = []

for i in range(m):
    tam = 0
    a = list(map(int,stdin.readline().strip().split()))
    for j in range(n):
        tc[j] += a[j]
        th[i] += a[j]
    mang.append(a)

q = int(stdin.readline().strip())
for _ in range(q):
    u,v = list(map(int,stdin.readline().strip().split()))
    stdout.write(str(th[u - 1]+tc[v-1]-mang[u-1][v-1]) + '\n')
