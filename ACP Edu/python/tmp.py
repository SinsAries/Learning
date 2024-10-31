s = input()

res = 0
i = 0
while i < len(s):
    dau = '?' # lay dau + hoac - o truoc moi so
    if not s[i].isdigit():
        dau = s[i]
        i += 1
    if(i == 0): # so dau tien la so duong
        dau = '+'

    j = i
    tam = s[i]
    while j + 1 < len(s) and s[j + 1].isdigit():
        j += 1
        tam += s[j]
    if j + 1 < len(s) and s[j + 1] == '*': # co phep nhan tiep theo
        j += 2
        so_tiep_theo = s[j]
        while j + 1 < len(s) and s[j + 1].isdigit():
            j += 1
            so_tiep_theo += s[j]
        tam = int(tam) * int(so_tiep_theo)
    else:
        tam = int(tam)
    
    if dau == '+':
        res += tam
    else:
        res -= tam

    # print(i, j, tam)

    i = j + 1

print(res)