from sys import stdin, stdout

k = int(stdin.readline().strip())
s = stdin.readline().strip()

n = len(s)
res = n * (n + 1) // 2

# Tinh so xau con co tong < k
l = 0
r = 0
curSum = 0
while r < n:
    curSum += int(s[r])
    while l <= r and curSum >= k:
        curSum -= int(s[l])
        l += 1
    if(curSum < k):
        res -= r - l + 1
    r += 1

# tinh so xau con co tong > k
l = 0
r = 0
curSum = 0
while r < n:
    curSum += int(s[r])
    while l <= r and curSum - int(s[l]) > k:
        curSum -= int(s[l])
        l += 1
    if(curSum > k):
        res -= l + 1
    r += 1

print(res)
    