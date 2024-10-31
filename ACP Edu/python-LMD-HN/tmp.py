n,q = map(int,input().split())
a = list(map(int,input().split()))

for _ in range(q):
    u,v,x = map(int,input().split())
    
    b = []
    for i in range(n):
        b.append(a[i])
    
    if u == 0 and v == 0:
        b[0:x] = sorted(b[0:x])
    if u == 0 and v == 1:
        b[0:x] = sorted(b[0:x],reverse = True)
    if u == 1 and v == 0:
        b[n-x:n] = sorted(b[n-x:n])
    if u == 1 and v == 1:
        b[n-x:n] = sorted(b[n-x:n],reverse = True)
        
    print(*b)
