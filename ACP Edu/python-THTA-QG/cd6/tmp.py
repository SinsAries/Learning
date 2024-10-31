x = int(input())
L = 0
R = 99999999999999999999999999999999999
while L + 1 < R:
    N = (L + R + 1) // 2

    if N * (N + 1) == x * 2:
        print("YES")
        exit()
    
    if(N * (N + 1) < x * 2):
        L = N
    else:
        R = N

print("NO")