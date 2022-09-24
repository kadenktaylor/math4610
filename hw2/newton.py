import math as math


def newton(f, df, x0, tol, v):
    print("newton iteration")
    if v == 0:
        if abs(f(x0[-1])) < tol:
            return x0
        else:
            x0_next = x0[-1] - f(x0[-1])/df(x0[-1])
            x0[-1] = x0_next
            return newton(f, df, x0, tol, 0)
    else:
        if abs(f(x0[-1])) < tol:
            return x0
        else:
            x0_next = x0[-1] - f(x0[-1])/df(x0[-1])
            x0.append(x0_next)
            return newton(f, df, x0, tol, 1)


f = lambda x: x*math.e**(-x)
df = lambda x: math.e**(-x) - (x * math.e**(-x))

x0 = [.1]

print(f"Newton Method: {newton(f, df, x0, .00000001, 1)}")

