import math


def bisection(f_expression, a, b, tol, maxIter, v):
    f = lambda x: eval(f_expression)
    values = []
    a = float(a)
    b = float(b)
    tol = float(tol)
    maxIter = int(maxIter)
    c = 1010101010101010101.0
    v = int(v)
    k = int(math.log(tol / (b-a)) / math.log(1/2)) + 1
    if k > maxIter:
        k = maxIter
    for i in range(0, k):
        c = .5 * (a + b)
        if v:
            values.append(c)
            values.append(b - a)
        if f(c) == 0:
            break
        if f(a) * f(c) < 0:
            b = c
        else:
            a = c
    if not v:
        values.append(c)
        values.append(b - a)
    return values

