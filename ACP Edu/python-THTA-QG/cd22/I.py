a = int(input())
b = int(input())
n = int(input())
a %= b

vis = [False] * b
digit = []
while not vis[a]:
    vis[a] = True
    a *= 10
    while(a < b):
        a *= 10
        digit.append(0)
    digit.append(a // b)
    a %= b

n -= 1
print(digit[n % len(digit)])