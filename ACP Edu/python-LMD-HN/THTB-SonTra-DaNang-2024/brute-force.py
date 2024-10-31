n = int(input())

n **= 2

def isSqr(n):
    return int(n ** 0.5) ** 2 == n

i = 1
res = 0

while True:
    if(i * i > n):
        break
    if(n % i != 0):
        i += 1
        continue

    a = i
    b = n // i

    x = (b - a) // 2
    y = (b - x)

    if(x > 0 and y > 0 and n + x**2 == y**2):
        # print(x, y)
        res += 1
    i += 1

print(res)