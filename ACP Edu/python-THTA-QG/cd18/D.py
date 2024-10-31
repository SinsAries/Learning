A = []
for _ in range(3):
    A.append(list(map(int, input().split())))
k = int(input())
opes = list(map(int, input().split()))

def inRa(X):
    for i in X:
        print(*i)

def opeType1():
    B = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]

    B[0][1] = A[0][0]
    B[0][2] = A[0][1]
    B[1][2] = A[0][2]
    B[2][2] = A[1][2]
    B[2][1] = A[2][2]
    B[2][0] = A[2][1]
    B[1][0] = A[2][0]
    B[0][0] = A[1][0]

    inRa(B)

    del A[0:3]
    for i in B:
        A.append(i)

def opeType2():
    B = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
    for i in A:
        B.append(i)

    B[0][1] = A[0][2]
    B[1][1] = A[0][1]
    B[2][1] = A[1][1]
    B[2][2] = A[2][1]
    B[2][3] = A[2][2]
    B[1][3] = A[2][3]
    B[0][3] = A[1][3]
    B[0][2] = A[0][3]

    del A[0:3]
    for i in B:
        A.append(i)

for ope in opes:
    if(ope == 1):
        opeType1()
    else:
        opeType2()
    print(A)
for i in A:
    print(*i)