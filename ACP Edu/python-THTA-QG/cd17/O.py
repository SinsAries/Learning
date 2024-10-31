from sys import stdin, stdout

N = int(stdin.readline().strip())  
A = list(map(int, stdin.readline().split()))

pref = [0] * (N + 1)
idx = 1
firstPos = {}
firstPos[0] = 0
res = 0
for i in A:
    if i == 1:
        pref[idx] = pref[idx - 1] + 1
    else:
        pref[idx] = pref[idx - 1] - 1
    
    if pref[idx] in firstPos:
        res = max(res, idx - firstPos[pref[idx]])
    else:
        firstPos[pref[idx]] = idx

    idx += 1
stdout.write(str(res) + '\n')   