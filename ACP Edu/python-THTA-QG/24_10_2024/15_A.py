n, k = map(int, input().split())
a = list(map(int, input().split()))
queries = list(map(int, input().split()))

mark = {}
for i in range(n):
    mark[a[i]] = 1

for x in queries:
    if (x in mark):
        print("YES")
    else:
        print("NO")