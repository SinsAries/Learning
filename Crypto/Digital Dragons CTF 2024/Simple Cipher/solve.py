tmp = 'afle{d89gbf1e1693ac6abca8df52a53afb0d}'
# for l in range(2, len(tmp) + 1):
#     newTmp = tmp + 'X' * (l - len(tmp) % l)
#     res = [list(newTmp[i:i + l]) for i in range(0, len(newTmp), l)]
#     for i in range(l):
#         if(res[0][i] == 'f' and res[1][i] == 'l'):
#             for j in res:
#                 print(j)
#             print()
#             break
# tmp += 'X' * 2
res = []
for i in range(5):
    res.append([tmp[i + j *5] for j in range(8)])
for i in res:
    print(i)