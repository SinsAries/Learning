Q = int(input())
queries = [] * Q

isSubtask1 = True

for _ in range(Q):
    L, R, X = map(int, input().split())
    queries.append((L, R, X))
    if R > 1000:
        isSubtask1 = False
if(Q > 1000):
    isSubtask1 = False

def sumDivisors(val):
    res = 0
    for i in range(1, int(val**0.5) + 1):
        if val % i == 0:
            res += i
            if i != val // i:
                res += val // i
    return res - val

sumDiv = [0] * 100001
for i in range(1, 100001):
    sumDiv[i] = sumDivisors(i)

if isSubtask1:
    for query in queries:
        L, R, X = query
        res = 0
        for i in range(L, R + 1):
            if sumDiv[i] > X:
                res += 1
        print(res)
    exit()

pref = []
for x in range(10):
    pref.append([0] * 100001)
    for i in range(1, 100001):
        pref[x][i] = pref[x][i - 1]
        if sumDiv[i] > x + 1:
            pref[x][i] += 1

for query in queries:
    L, R, X = query
    print(pref[X - 1][R] - pref[X - 1][L - 1])