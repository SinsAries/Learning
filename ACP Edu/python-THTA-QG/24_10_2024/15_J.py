from sys import stdin, stdout
read = stdin.readline
write = stdout.write

n = int(read())
phu_huynh = {}
for _ in range(n):
    hs, ph = read().split()
    phu_huynh[hs] = ph

m = int(input())
for _ in range(m):
    hs = read()[:-1]
    if(hs in phu_huynh):
        write(phu_huynh[hs] + "\n")
    else:
        write("Khong tim thay thong tin phu huynh.\n")