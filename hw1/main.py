import fixedPointIteration as fp
import bisection as bi

f = input("Enter a value for f(x) = ")
g = input("Enter a value for g(x) = ")
a = input("Enter a value for a = ")
b = input("Enter a value for b = ")
x0 = input("Enter a value for x0: ")
tol = input("Enter a value for tol: ")
maxIter = input("Enter a value for maxIter: ")
fixed = fp.fixedPointIter(g, x0, tol, maxIter)
bisec = bi.bisection(f, a, b, tol, maxIter)
print(f"FixedPoint: x = {fixed}")
print(f"Bisection: x = {bisec}")
