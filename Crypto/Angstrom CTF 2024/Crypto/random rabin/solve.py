from sage.all import *
from pwn import *
import json

def solve(n, c):
    c = c * c % n
    P = PolynomialRing(Zmod(n), 'x')
    f = P.gen() * P.gen() - c
    f = f.monic()
    print(f.small_roots(X = 2**128 + 1))
    return str(hex(min(f.small_roots(X = 2**128 + 1))))[2:]

# # context.log_level = 'debug'
r = remote('challs.actf.co', 31300, level = 'debug')

for _ in range(65):
    n = int(r.recvuntil(b'plaintext: ').decode()[:-11].split(' ')[1][:-1])
    print()
    print(n)
    c = int(r.recvuntil(b'gimme the secret: ').decode()[:-19])
    print()
    print(c)
    # n = 64497324988367195218876991113031925648264574421224602668129550601352939310478735658019119648128299957819486696516436098924044612575915264756553107600313477980486186653996632084834645677146741923043591854883561841205853903910942648482950147578357412517784765969798741355969346109300867306266848698484847029281
    # c = 26586675056116709825188453005407001124539588126453059745850135847446723575741604719640008978367162374004586365144193825508727886146414482703318085939273147798867736478725663417684938991059859619855152227685394364957970992694547972789240965296541538581862735619092693421296276166162206809047442666870164445875
    ans = solve(n, c)
    # print(hex(ans))
    # r.recvuntil(b'gimme the secret: ')
    print("finished round ", _)
    while(len(ans) < 32):
        ans = '0' + ans
    r.sendline((ans).encode())
