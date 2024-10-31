from sys import stdin, stdout

S = stdin.readline().strip()
T = stdin.readline().strip()

res = 0

for i in range(len(S)):
    if(i + len(T) > len(S)):
        break
    j = i
    while j - i < len(T) and S[j] == T[j - i]:
        j += 1
    if j - i == len(T):
        res += 1

stdout.write(str(res) + '\n')