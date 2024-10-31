from sys import stdin, stdout
import math

a, b = map(int, stdin.readline().split(' '))
stdout.write(str(math.gcd(a, b)))