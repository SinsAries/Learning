N = int(input())
a = list(map(int, input().split()))
Q = int(input())

pref = [0]
for i in a:
    pref.append(pref[-1] + i)
for _ in range(Q):
    L, R, U, V = map(int, input().split())
    if(pref[R] - pref[L - 1] > pref[V] - pref[U - 1]):
        print("YES")
    else:
        print("NO")