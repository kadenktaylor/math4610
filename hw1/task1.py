import math


def f(x):
    return x - 3  # x * (math.e ** (-x))


def g1(x):
    return x - f(x)


def g2(x):
    return x + f(x)


def fixedPointInter (x0, tol, maxIter):
    x0 = float(x0)
    tol = float(tol)
    maxIter = int(maxIter)

    for i in range(0, maxIter):
        x1 = g1(x0)
        print(f"Durning iteration {i} the value went from {f(x0)} to {f(x1)}")
        error = abs(x1 - x0)
        print(f"The error for iteration {i} is: {error}")
        x0 = x1
        if error < tol:
            break

    return x0


x0 = input("Enter a value for x0: ")
tol = input("Enter a value for tol: ")
maxIter = input("Enter a value for maxIter: ")
approx = fixedPointInter(x0, tol, maxIter)
print(f"The approximation for the root is at {approx} with f(x) = {approx}")
