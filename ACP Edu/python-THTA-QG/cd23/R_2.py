n, m, k = map(int, input().split())

def roundUp(a, b):
    if(a % b == 0):
        return a // b
    else:
        return a // b + 1
    
print(roundUp(n, k) * roundUp(m, k))