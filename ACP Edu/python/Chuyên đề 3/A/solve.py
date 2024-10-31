a = input().split(' ')
ch = a[0]
n = int(a[1])

ch = ord(ch) - ord('a')
ch = (ch + n) % 26
ch = ch + ord('a')

print(chr(ch))