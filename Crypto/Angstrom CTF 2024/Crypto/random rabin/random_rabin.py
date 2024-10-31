from random import SystemRandom
from Crypto.Util.number import getPrime
from libnum import xgcd
from sage.all import *
from pwn import *
import json

random = SystemRandom()

def primegen():
	while True:
		p = getPrime(512)
		if p % 4 == 3:
			return p

def keygen():
	p = primegen()
	q = primegen()
	n = p * q
	return n, (n, p, q)

def encrypt(pk, m):
	n = pk
	return pow(m, 2, n)

def decrypt(sk, c):
	n, p, q = sk
	yp, yq, _ = xgcd(p, q)
	mp = pow(c, (p + 1)//4, p)
	mq = pow(c, (q + 1)//4, q)
	s = yp * p * mq % n
	t = yq * q * mp % n
	rs = [(s + t) % n, (-s - t) % n, (s - t) % n, (-s + t) % n]
	r = random.choice(rs)
	return r

def solve(n, c):
    c = c * c % n
    P = PolynomialRing(Zmod(n), 'x')
    f = P.gen() * P.gen() - c
    f = f.monic()
    print(f.small_roots(X = 2**128 + 1))
    return str(hex(min(f.small_roots(X = 2**128 + 1))))[2:]

def game():
	pk, sk = keygen()
	print(f'pubkey: {pk}')
	secret = random.randbytes(16)
	m = int.from_bytes(secret, 'big')
	c = decrypt(sk, encrypt(pk, m))
	print(solve(pk, c))
	print('m ', m)
	print(hex(m))
	print(f'plaintext: {c}')
	guess = bytes.fromhex(input('gimme the secret: '))
	return guess == secret

if __name__ == '__main__':
	for _ in range(64):
		success = game()
		if not success:
			exit()

	flag = "CACCAC"
	print(flag)
