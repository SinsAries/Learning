Q = int(input())
for _ in range(Q):
    A, B = map(int, input().split())
    newA = A

    i = 2
    while i * i <= A:
        if A % i == 0:
            cnt = 0
            while A % i == 0:
                A //= i
                cnt += 1
            if(cnt % 2 == 1):
                newA *= i
        i += 1
    if A > 1:
        newA *= A

    l = 0
    r = 1000000000
    while l + 1 < r:
        m = (l + r + 1) // 2
        if m * m * newA > B:
            r = m
        else:
            l = m
    print(r * r * newA)