def calc_num(i):
    return 1 + (i - 1) * i

n = int(input())

A_n = calc_num(n)
A_n_plus_1 = calc_num(n + 1)

target = A_n * A_n_plus_1

l = 0
r = target
while l + 1 < r:
    m = (l + r) // 2

    if(calc_num(m) == target):
        print(m)
        exit()

    if calc_num(m) < target:
        l = m
    else:
        r = m