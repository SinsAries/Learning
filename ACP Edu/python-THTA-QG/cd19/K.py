a, b = map(int, input().split())
def giaiThua(x):
    if x == 0:
        return 1
    for i in range(2, x):
        x *= i
    return x % 1000000007
print(giaiThua(min(a, b)))