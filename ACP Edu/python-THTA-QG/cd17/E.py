from sys import stdin, stdout

N = int(stdin.readline().strip())

l = 0
r = 10**15

while l + 1 < r:
    m = (l + r + 1) // 2
    if m * (m + 1) // 2 == N:
        print("YES")
        exit()

    if m * (m + 1) // 2 < N:
        l = m
    else:
        r = m
print("NO")