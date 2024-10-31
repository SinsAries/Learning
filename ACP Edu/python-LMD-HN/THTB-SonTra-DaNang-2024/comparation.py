from pwn import *

for i in range(2, 1000):
    # context.log_level = 'debug'
    r = process(["python3", "solve.py"])
    r.sendline(str(i))
    res1 = r.recvall()
    r = process(["python3", "brute-force.py"])
    r.sendline(str(i))
    res2 = r.recvall()
    print(i, ":\n")
    print(res1)
    print(res2)

    if(res1 == res2):
        print("ACCEPTED")
    else:
        print("WRONG")
        break
