from pwn import *
import json
# context.log_level = 'debug'
r = remote('challenge.nahamcon.com', 32639)

r.recvuntil(b'> ')

r.send("1\n".encode())

r.recvuntil(b'> ')
r.send((chr(2)+'\n').encode())

r.recvuntil(b'Your encrypted message:\n')
c = int(str(r.recvline())[5:-4])


'''
    binary search for e
'''
e = 0
left = 1
right = 2000
while(left + 1 < right):
    m = left + (right - left + 1) // 2
    if(pow(2, m) == c):
        e = m
        break
    if(pow(2, m) > c):
        right = m
    if(pow(2, m) < c):
        left = m

'''
    get N and encrypted flag
'''

r.recvuntil(b'> ')
r.send("2\n".encode())
r.recvuntil(b'Your randomly chosen N:\n')
N = int(r.recvline().decode()[2:-1])
r.recvuntil(b'Your encrypted message:\n')
nums = [int(num) for num in r.recvline().decode()[3:-2].split(", ")]

flag = ''
for num in nums:
    for i in range(256):
        if(pow(i, e, N) == num):
            flag += chr(i)
print(flag)