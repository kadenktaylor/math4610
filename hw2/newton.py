import math as math


def newton(f, df, x0, tol):
    print("newton iteration")
    if abs(f(x0)) < tol:
        return x0
    else:
        return newton(f, df, x0 - f(x0)/df(x0), tol)


f = lambda x: x*math.e**(-x)
df = lambda x: math.e**(-x) - (x * math.e**(-x))

print(f"Newton Method: {newton(f, df, .5, .00000001)}")

