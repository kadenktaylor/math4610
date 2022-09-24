import math as math


def secant(f, x0, tol, v):
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


