import random

not_nhac = ['mì', 'fà', 'sòl', 'là', 'sì', 'đồ']

def sinh_not(n):
    for _ in range(n):
        print(random.choice(not_nhac), end=' ')

sinh_not(10)