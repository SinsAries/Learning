i = input().split(' ')
ch = i[0]
N = int(i[1])
print(chr((ord(ch) - ord('a') + N) % 26 + ord('a')))