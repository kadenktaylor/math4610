import math


def f(x):
    return x * (math.e ** (-x))


def bisection(a, b, tol, maxIter):
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


a = input("Enter a value for a: ")
b = input("Enter a value for b: ")
tol = input("Enter a value for tol: ")
maxIter = input("Enter a value for maxIter: ")
approx = bisection(float(a), float(b), float(tol), int(maxIter))
print(f"The approximation for the root is at {approx} with f(x) = {f(approx)}")

