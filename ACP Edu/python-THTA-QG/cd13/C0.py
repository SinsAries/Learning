N = int(input())
A = list(map(int, input().split()))

visited = [False] * N
for i in A:
    visited[i-1] = True

for i in range(N):
    if not visited[i]:
        print(i+1)
        break