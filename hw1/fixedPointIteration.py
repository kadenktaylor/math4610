import math


def fixedPointIter(g_expression, x0, tol, maxIter):
    g = lambda x: eval(g_expression)
    x0 = float(x0)
    tol = float(tol)
    maxIter = int(maxIter)

    for i in range(0, maxIter):
        x1 = g(x0)
        print(f"Durning iteration {i} the value went from {g(x0)} to {g(x1)}")
        error = abs(x1 - x0)
        print(f"The error for iteration {i} is: {error}")
        x0 = x1
        if error < tol:
            break

    return x0
