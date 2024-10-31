s = input()
dem = [0] * (ord('z') + 1)
for c in s:
    dem[ord(c)] += 1
for i in range(ord('a'), ord('z') + 1):
    if dem[i] > 0:
        print(chr(i), dem[i])
for i in range(ord('A'), ord('Z') + 1):
    if dem[i] > 0:
        print(chr(i), dem[i])