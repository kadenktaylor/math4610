import math as math


def secant(f, x0, x1, tol):
    print("newton iteration")
    if abs(f(x0)) < tol:
        return x0
    else:
        return secant(f, x1, x0 - ((x1-x0) * f(x0)) / (f(x1) - f(x0)), tol)


f = lambda x: x**2 - 3

print(f"Newton Method: {secant(f, 1.7, 1.6, .00000001)}")

