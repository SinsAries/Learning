def getPrimeFactorization(n):
    res = []
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                n //= i
                cnt += 1
            res.append((i, cnt))
    if n > 1:
        res.append((n, 1))
    return res

def getNumerOfDivisors(primes):
    res = 1
    for p, c in primes:
        res *= (c + 1)
    return res

n = int(input())

primes = getPrimeFactorization(n)
for i in range(len(primes)):
    primes[i] = (primes[i][0], primes[i][1] * 2)

numberOfDivisors = getNumerOfDivisors(primes)

# print(primes)

# loại bỏ trường hợp 2 ước không cùng tính chẵn lẻ
if(primes[0][0] == 2):
    numberOfDivisors -= numberOfDivisors // (primes[0][1] + 1) * 2

# loại bỏ trường hợp n * n
numberOfDivisors -= 1

# Những ước thỏa mãn thì chia đôi ra để lấy số cặp thỏa mãn
print(numberOfDivisors // 2)

