n = int(input())

for i in range(2, int(n**0.5) + 1):
    if n % i == 0:
        print(i, end = ' ')
        cnt = 0
        while n % i == 0:
            cnt += 1
            n //= i
        print(cnt)
        
if n > 1:
    print(n, 1)