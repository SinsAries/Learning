N = int(input())
A = list(map(int, input().split()))

isPrime = [True] * 1000001
def sieve():
    #...
sieve()

for num in A:
    if(num != int(num**0.5)**2):
        print('NO')
        continue
    sqrOfNum = int(num**0.5)
    if(sqrOfNum > 1000000):
        exit()
    if(not isPrime[sqrOfNum]):
        print('NO')
        continue
    print('YES')