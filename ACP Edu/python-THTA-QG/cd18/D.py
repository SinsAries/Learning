A = []
for _ in range(3):
    A.append(list(map(int, input().split())))
k = int(input())
opes = list(map(int, input().split()))

def opeType1():
    B = [[], [], []]
    for i in range(3):
        for j in range(4):
            B[i].append(A[i][j])

    B[0][1] = A[0][0]
    B[0][2] = A[0][1]
    B[1][2] = A[0][2]
    B[2][2] = A[1][2]
    B[2][1] = A[2][2]
    B[2][0] = A[2][1]
    B[1][0] = A[2][0]
    B[0][0] = A[1][0]

    return B

def opeType2():
    B = [[], [], []]
    for i in range(3):
        for j in range(4):
            B[i].append(A[i][j])

    B[0][1] = A[0][2]
    B[1][1] = A[0][1]
    B[2][1] = A[1][1]
    B[2][2] = A[2][1]
    B[2][3] = A[2][2]
    B[1][3] = A[2][3]
    B[0][3] = A[1][3]
    B[0][2] = A[0][3]

    return B

for ope in opes:
    if(ope == 1):
        A = opeType1()
    else:
        A = opeType2()

for i in A:
    print(*i)