from sys import stdin, stdout

class NUMBER:
    def __init__(self, val):
        self.val = val
    def __lt__(self, other):
        return self.val + other.val > other.val + self.val

T = int(stdin.readline().strip())

for _ in range(T):
    N, K = map(int, stdin.readline().strip().split())
    nums = []
    
    for i in range(1, N + 1):
        nums.append(NUMBER(str(i)))
    
    nums.sort()

    res = ''
    for i in nums:
        res += i.val
    if(len(res) < K):
        print(-1)
    else:
        print(res[K - 1])    