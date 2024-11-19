from sys import stdin

T = int(stdin.readline().strip())

def calc(x):
    res = 1
    i = 2
    while i * i <= x:
        if x % i == 0:
            cnt = 0
            while x % i == 0:
                cnt += 1
                x //= i
            if cnt % 2 == 1:
                res *= i
        i += 1
    if x > 1:
        res *= x
    return res

for _ in range(T):
    N = int(stdin.readline().strip())
    A = list(map(int, stdin.readline().strip().split()))

    cnt = {}
    res = 0
    for i in A:
        val = calc(i)
        if(val not in cnt):
            cnt[val] = 0
        res += cnt[val]
        cnt[val] += 1
    print(res)