import math


def hybrid_secant(f, a, b, tol, maxIter, v):
    error = 10.0*tol
    iteration = 0
    x0 = .49*(a+b)
    x1 = .51*(a+b)
    array =[]
    while error > tol and iteration < maxIter:
        x2 = x0 - ((x1-x0) * f(x0)) / (f(x1) - f(x0))
        secant_error = abs(x2 - x0)
        if secant_error > error:
            print("Bisection Iteration")
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
            x0 = .49*(a+b)
            x1 = .51*(a+b)
        else:
            print("Newton Iteration")
            x0 = x1
            x1 = x2
            error = secant_error
        iteration = iteration + 1
        if v == 1:
            array.append(x1)
            array.append(error)
    if v == 0:
        array.append(x1)
        array.append(error)
    return array
