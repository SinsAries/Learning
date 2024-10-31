class Curve:
    def __init__(self, p, a, b) -> None:
        self.p = p
        self.a = a % p
        self.b = b % p
        self.O = Point(self, 0, 0)

    def __str__(self):
        return f"y^2 = x^3 + {self.a} * x + {self.b} (mod {self.p})"

class Point:
    def __init__(self, E: Curve, x: int, y: int) -> None:
        self.E = E
        self.x = x % E.p
        self.y = y % E.p

    def __str__(self):
        return "(" + str(self.x) + ", " + str(self.y) + ")"

    def __neg__(self) -> 'Point':
        return Point(self.E, self.x, -self.y)

    def __add__(self, other: 'Point') -> 'Point':
        assert self.E == other.E
        E = self.E

        if other == E.O:
            return self
        if self == E.O:
            return other

        xP, yP = self.x, self.y
        xQ, yQ = other.x, other.y

        if xP == xQ:
            if (yP + yQ) % E.p == 0:
                return E.O
            m = (3*xP**2 + E.a) * pow(2*yP, -1, E.p) % E.p
        else:
            m = (yQ - yP) * pow(xQ - xP, -1, E.p) % E.p

        xR = m**2 - xP - xQ
        yR = m * (xP - xR) - yP
        return Point(E, xR, yR)

    def __sub__(self, other: 'Point') -> 'Point':
        return self + -other

    def __mul__(self, k: int) -> 'Point':
        P, R = self, self.E.O
        if k < 0:
            P = -P
            k *= -1

        while k:
            if k % 2:
                R += P
            P += P
            k //= 2
        return R

    __rmul__ = __mul__

    def __eq__(self, o: 'Point') -> bool:
        return isinstance(o, Point) \
            and self.E == o.E       \
            and self.x == o.x       \
            and self.y == o.y

    def compress(self):
        x_byte = int.to_bytes(self.x, 592//8, "big")
        y_byte = int.to_bytes(self.y, 592//8, "big")
        return (x_byte + y_byte).hex()

def evaluate(x, a, b, p):
    y2 = (x**3 + a * x + b) % p 
    y = pow(y2, ((p+1)//4), p)
    assert pow(y, 2, p) == y2 % p
    return y