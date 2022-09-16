import math


def bisection(f_expression, a, b, tol, maxIter):
    f = lambda x: eval(f_expression)
    a = float(a)
    b = float(b)
    tol = float(tol)
    maxIter = int(maxIter)
    c = 1010101010101010101
    k = int(math.log(tol / (b-a)) / math.log(1/2)) + 1
    print(f"The value of k is: {k}")
    if k > maxIter:
        k = maxIter
    for i in range(0, k):
        c = .5 * (a + b)
        print(f"Iteration {i}, c = {c} ")
        if f(c) == 0:
            break
        if f(a) * f(c) < 0:
            b = c
        else:
            a = c
    return c

