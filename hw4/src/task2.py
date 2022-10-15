import math as m

x0 = m.pi / 4


def f_function(x):
    return ((x-(m.pi/2))*m.tan(x)*m.tan(x)) / (x*x + 65)


def fprime(f, x0, h):
    top = f(x0 + h) - 2*f(x0) + f(x0-h)
    bottom = h*h
    return top / bottom


for i in range(1, 10):
    h = 1 / 10**i
    result = fprime(f_function, x0, h)
    print(f"With h = {h} the approximation is: {result}")

