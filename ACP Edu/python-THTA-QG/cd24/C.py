N = int(input())
K = int(input())
D = int(input())

cntK = 6 * [0]
cntD = 6 * [0]

while(K % 2 == 0):
    cntK[2] += 1
    K //= 2
while(K % 3 == 0):
    cntK[3] += 1
    K //= 3
while(K % 5 == 0):
    cntK[5] += 1
    K //= 5

while(D % 2 == 0):
    cntD[2] += 1
    D //= 2
while(D % 3 == 0):
    cntD[3] += 1
    D //= 3
while(D % 5 == 0):
    cntD[5] += 1
    D //= 5

tmp = 1
tmp *= 2 ** max(0, cntD[2] - cntK[2])
tmp *= 3 ** max(0, cntD[3] - cntK[3])
tmp *= 5 ** max(0, cntD[5] - cntK[5])

print(N // tmp)

