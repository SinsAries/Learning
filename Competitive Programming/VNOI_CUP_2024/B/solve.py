def solve():
    global n, a, b
    n = int(input())
    a = input().split(' ')
    b = input().split(' ')

    a = [int(x) for x in a]
    b = [int(x) for x in b]

    for i in range(n-1, 0, -1):
        if a[i] >= b[i]:
            a[i-1] += (a[i] - b[i]) * 2
            a[i] = b[i]
    
    for i in range(n-1):
        if a[i] >= b[i]:
            tmp = (a[i] - b[i]) // 2
            a[i+1] += tmp
            a[i] -= tmp * 2
    
    for i in range(n-1, 0, -1):
        if a[i] >= b[i]:
            a[i-1] += (a[i] - b[i]) * 2
            a[i] = b[i]
    
    ok = all(a[i] >= b[i] for i in range(n))
    if(ok):
        print('YES')
    else:
        print('NO')

TC = 1
TC = int(input())
while (TC > 0):
    solve()
    TC -= 1