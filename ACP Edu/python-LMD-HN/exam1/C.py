def sumDivisors(x):
    sum = 0
    for i in range(1, int(x**0.5) + 1):
        if(x % i == 0):
            sum += i
            j = x // i
            if(j != i):
                sum += j
    return sum

N = int(input())
sum = sumDivisors(N)
if(sumDivisors(sum) == sum + 1):
    print("YES")
else:
    print("NO")
