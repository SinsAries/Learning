n = int(input())
dem = 0
t1 = -1
t2 = 0
kt = True
kq = 0
tam = 1
while dem < n:
    if kt:
        if(dem + tam >= n):
            kq += (n - dem) * (t1 + 2 + t1 + (n - dem) * 2) // 2
            t1 += 2 * (n - dem)
            print(t1)
            print(kq)
            exit()
        else:
            kq += tam * (t1 + 2 + t1 + 2 * tam) // 2
            dem += tam
            t1 += 2 * tam

        kt = False
    else:
        if(dem + tam >= n):
            kq += (n - dem) * (t2 + 2 + t2 + (n - dem) * 2) // 2
            t2 += 2 * (n - dem)
            print(t2)
            print(kq)
            exit()
        else:
            kq += tam * (t2 + 2 + t2 + 2 * tam) // 2
            dem += tam
            t2 += 2 * tam

        kt = True
    tam += 1