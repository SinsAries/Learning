X = int(input())
K = int(input())
N = int(input())

da_gap = [False] * 100

X %= 100

cnt = 0

while da_gap[X] == False:
    print(X)
    cnt += 1
    da_gap[X] = True
    X += K
    X %= 100

print(X)
print(cnt)