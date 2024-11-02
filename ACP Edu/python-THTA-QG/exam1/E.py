n = int(input())
a = list(map(int,input().split()))
t = sum(a)
q = int(input())
for _ in range(q):
    i,val = map(int,input().split())
    t -= a[i-1]
    t += val
    a[i - 1] = val
    print(t)
