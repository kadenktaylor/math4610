import fixedPointIteration as fp
import bisection as bisection

f = input("Enter a value for f(x) = ")
g = input("Enter a value for g(x) = ")
a = input("Enter a value for a = ")
b = input("Enter a value for b = ")
x0 = input("Enter a value for x0: ")
tol = input("Enter a value for tol: ")
maxIter = input("Enter a value for maxIter: ")
approx = fp.fixedPointIter(g, x0, tol, maxIter)
print(f"The approximation for the root is at {approx} with f(x) = {approx}")