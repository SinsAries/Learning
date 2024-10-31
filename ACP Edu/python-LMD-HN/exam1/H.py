from sys import stdin, stdout
from functools import cmp_to_key

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
    res = '-1'
    i = 0
    while K > 0 and i < N:
        if K <= len(nums[i].val):
            res = nums[i].val[K - 1]
            break
        K -= len(nums[i].val)
        i += 1
    stdout.write(res + '\n')