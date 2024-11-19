from sys import stdin, stdout
q = int(stdin.readline().strip())
for _ in range(q):
    n = int(stdin.readline().strip())
    res = n // 8 * 2
    if(n % 8 >= 4):
        res += 1
    stdout.write(str(int(res)) + '\n')