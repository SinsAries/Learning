from sys import stdin, stdout

n = int(stdin.readline().strip())
a = list(map(int, stdin.readline().strip().split()))

cnt = [0] * 3
res = 0 
for i in a:
    if(i % 2 == 0):
        res += cnt[(3 - (i % 3)) % 3]
    cnt[i % 3] += 1
stdout.write(str(res) + '\n')