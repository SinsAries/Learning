from math import sqrt
n = int(input())
sum = 0
for i in range(1, int(sqrt(n)) + 1, 1):
    if n % i == 0:
        sum += i
        if(n // i != i):
            sum += n // i

if(n * 2 == sum):
    print("YES")
else:
    print("NO")