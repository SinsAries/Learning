n, m, k = map(int, input().split())

res = (n // k) * (m // k)
if(n % k != 0):
    res += m // k
if(m % k != 0):
    res += n // k
if(n % k != 0 and m % k != 0):
    res += 1

print(res)