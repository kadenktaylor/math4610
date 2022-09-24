import math


def hybrid_newton(f, df, a, b, tol, maxIter, v):
    error = 10.0*tol
    iteration = 0
    x0 = .5*(a+b)
    array = []
    while error > tol and iteration < maxIter:
        x1 = x0 - f(x0)/df(x0)
        newton_error = abs(x1 - x0)
        if newton_error > error:
            fa = f(a)
            fb = f(b)
            for i in range(1, 4):
                c = 0.5*(a+b)
                fc = f(c)
                if fa*fc < 0:
                    b = c
                    fb = fc
                else:
                    a = c
                    fa = fc
            error = abs(b-a)
            x0 = .5*(a + b)
        else:
            x0 = x1
            error = newton_error
        iteration = iteration + 1
        if v == 1:
            array.append(x0)
            array.append(error)
    if v == 0:
        array.append(x0)
        array.append(error)
    return array
