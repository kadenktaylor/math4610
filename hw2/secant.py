import math as math


def secant(f, x0, tol, v):
    print("secant iteration")
    if v == 0:
        if abs(f(x0[-1])) < tol:
            return x0
        else:
            x0_next = x0[-2] - ((x0[-1]-x0[-2]) * f(x0[-2])) / (f(x0[-1]) - f(x0[-2]))
            x0[-2] = x0[-1]
            x0[-1] = x0_next
            return secant(f, x0, tol, 0)
    else:
        if abs(f(x0[-1])) < tol:
            return x0
        else:
            x0_next = x0[-2] - ((x0[-1]-x0[-2]) * f(x0[-2])) / (f(x0[-1]) - f(x0[-2]))
            x0.append(x0_next)
            return secant(f, x0, tol, 1)


f = lambda x: x**2 - 3

x0 = [1.6, 1.7]

print(f"Newton Method: {secant(f, x0, .00000001, 1)}")

