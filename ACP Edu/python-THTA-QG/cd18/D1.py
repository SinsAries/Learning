n, m, k = map(int, input().split())

cnt_row = [0] * 501
cnt_col = [0] * 501
cnt_add = [0] * 1001
cnt_sub = [0] * 999
res = 0
cnt = 0

for _ in range(k):
    i, j = map(int, input().split())
    res += cnt_row[i] + cnt_col[j] + cnt_add[i + j] + cnt_sub[i - j + 499]

    cnt_row[i] += 1
    cnt_col[j] += 1
    cnt_add[i + j] += 1
    cnt_sub[i - j + 499] += 1

print(res)