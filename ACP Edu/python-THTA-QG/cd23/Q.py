n = int(input())

def lastOf(num):
    if(num % 2 == 0):
        return (num + 2) * ((num - 2) // 2 + 1)
    else:
        return (num + 1) * ((num - 1) // 2 + 1) - 1

def sumOf(num):
    if(num % 2 == 0):
        return (lastOf(num) + 2) * lastOf(num) // 4
    else:
        return (lastOf(num) + 1) * (lastOf(num) + 1) // 4

l = 0
r = n + 1
while l + 1 < r:
    m = (l + r + 1) // 2
    if m * (m + 1) // 2 >= n:
        r = m
    else:
        l = m

vi_tri = n - (r - 1) * r // 2
curNum = lastOf(r - 2) + vi_tri * 2
print(curNum)
print(sumOf(r - 1) + sumOf(r - 2) + (curNum + (curNum - vi_tri * 2 + 2)) * (vi_tri) // 2)