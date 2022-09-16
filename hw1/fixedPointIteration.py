import math


def fixedPointIter(g_expression, x0, tol, maxIter, v):
    values = []
    error = 0
    g = lambda x: eval(g_expression)
    x0 = float(x0)
    tol = float(tol)
    maxIter = int(maxIter)
    v = int(v)

    for i in range(0, maxIter):
        x1 = g(x0)
        error = abs(x1 - x0)
        x0 = x1
        if v:
            values.append(x0)
            values.append(error)
        if error < tol:
            break
    if not v:
        values.append(x0)
        values.append(error)
    return values
