from sys import stdin, stdout

N = int(stdin.readline().strip())
a = list(map(int, stdin.readline().strip().split()))
Q = int(stdin.readline().strip())

sum = 0
for i in a:
    sum += i

for _ in range(Q):
    i, val = map(int, stdin.readline().strip().split())
    i -= 1
    sum += (val - a[i])
    a[i] = val
    print(sum)