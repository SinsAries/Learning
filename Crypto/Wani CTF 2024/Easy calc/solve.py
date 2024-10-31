with open("output.txt") as f:
    p = int(f.readline().split(" = ")[1])
    A = int(f.readline().split(" = ")[1])
    ciphertext = f.readline().split(" = ")[1][1:-2]

print(p)
print(A)
print(ciphertext)
iv = ciphertext[:32]
ciphertext = ciphertext[32:]
print(len(ciphertext))