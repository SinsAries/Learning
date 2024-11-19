A = int(input())
T = int(input())
K = int(input())

res = 0

def upd(num):
    global res
    res += ((num // 10) == K)
    res += ((num % 10) == K)

upd(A)
for _ in range(T % 60):
    A += 1
    upd(A)

if(T > 60):
    res += (T // 60) * 6 # số lần số K xuất hiện ở hàng đơn vị
    if(K <= 5):
        res += (T // 60) * 10 # số lần số K xuất hiện ở hàng chục

print(res)