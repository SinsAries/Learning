flag = 'cixd{05655105yz79321bzz38b7456c028bc1}'
key = ord('f') - ord('c')
res = ""
alphabet = "abcdefghijklmnopqrstuvwxyz"
for i in flag:
    if i in alphabet:
        res += chr((ord(i) - ord('a') + key) % 26 + ord('a'))
    else:
        res += i
print(res)