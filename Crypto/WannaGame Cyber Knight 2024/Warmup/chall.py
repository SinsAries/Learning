from Crypto.Util.number import * 
from Crypto.Util.Padding import pad 
from flag import flag 
from gmpy2 import next_prime

message = b"The challenge's flag is: " + flag
assert len(message) % 3 == 0

part1 = message[ : len(message)//3]
part2 = message[len(message)//3 : 2*len(message)//3]
part3 = message[2*len(message)//3 : ]
sep = "#"*50

### part 1: Warm-up!!!
p1 = getPrime(512)
q1 = getPrime(512)
e1 = 11
n1 = p1 * q1
c1 = pow(bytes_to_long(part1), e1, n1)
print(f'{n1 = }')
print(f'{c1 = }')
print(sep)

### part 2: One more warm-up
p2 = getPrime(1024)
q2 = getPrime(1024)
n2 = p2*q2 
e2 = 17
print(f'{n2 = }')
print(f'Real: {pow(bytes_to_long(part2), e2, n2)}')
print(f'Fake: {pow(bytes_to_long(pad(part2, 16)), e2, n2)}')
print(sep)

### part 3: The last "warm-up"
p3,q3 = getPrime(1024), getPrime(1024)
n3 = p3 * q3
power1, power2 = getPrime(128), getPrime(128)
hint1 = pow((5*p3 + q3), power1, n3)
hint2 = pow((3*p3 - 6*q3), power2, n3)

e3 = next_prime(hint1 + hint2)
c3 = pow(bytes_to_long(part3), e3, n3)
print(f'{power1 = }')
print(f'{power2 = }')
print(f'{n3 = }')
print(f'{hint1 = }')
print(f'e3 = {e3}')
print(f'c3 = {c3}')
