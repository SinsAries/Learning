from sage.all import *

mat = []
solution = [-2561342656, -2561342656, -2561342656, -2561342656, -2561342656, -2561342656, -2561342656, -2561342656]
bases = [-37, -9, -4, 5, 6, 17, 44, 58]
for i in range(8):
    solution[i] -= (bases[i]**8)
for base in bases:
    row = []
    for i in range(7):
        row.append(base ** (i + 1))
    row.append(0)
    mat.append(row)

A = matrix(mat)
b = vector(solution)
x = A.solve_left(b)

print(x)

# print(matrix)


'''
import galois
import numpy as np
MOD = 7514777789

points = []

for line in open('encoded.txt', 'r').read().strip().split('\n'):
    x, y = line.split(' ')
    points.append((int(x), int(y)))

GF = galois.GF(MOD)

matrix = []
solution = []
for point in points:
    x, y = point
    solution.append(GF(y % MOD))

    row = []
    for i in range(len(points)):
        row.append(GF((x ** i) % MOD))
    
    matrix.append(GF(row))

open('output.bmp', 'wb').write(bytearray(np.linalg.solve(GF(matrix), GF(solution)).tolist()[:-1]))
'''