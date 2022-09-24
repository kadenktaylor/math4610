import fixedPointIteration as fp
import bisection as bi
import math
import sys

if len(sys.argv) > 8:
        f = sys.argv[1]
        g = sys.argv[2]
        a = sys.argv[3]
        b = sys.argv[4]
        x0 = sys.argv[5]
        tol = sys.argv[6]
        maxIter = sys.argv[7]
        v = sys.argv[8]
else:
    print("Don't add any parenthesis to the equations")
    f = input("Enter a value for f(x) = ")
    g = input("Enter a value for g(x) = ")
    a = input("Enter a value for a = ")
    b = input("Enter a value for b = ")
    x0 = input("Enter a value for x0: ")
    tol = input("Enter a value for tol: ")
    maxIter = input("Enter a value for maxIter: ")
    v = input("Print full table? 1 = Yes, 0 = No: ")

fixed = fp.fixedPointIter(g, x0, tol, maxIter, v)
bisec = bi.bisection(f, a, b, tol, maxIter, v)

function = lambda x: eval(f)

print("\nIf the full table is not requested, the final iteration will show as iteration 0\n")

print("----Fixed Point Iteration------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      Error  ")
print("-------------------------------------------------------------------------------------------")
for i in range(0, int(len(fixed)/2)):
    print(f"{i:>3}  |  {fixed[i*2]:<25}  |  {function(fixed[i*2]):<25}  |  {fixed[i*2 + 1]:<25}")
print("-------------------------------------------------------------------------------------------")

print("----------Bisection------------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      Error  ")
print("-------------------------------------------------------------------------------------------")
for i in range(0, int(len(bisec)/2)):
    print(f"{i:>3}  |  {bisec[i*2]:<25}  |  {function(bisec[i*2]):<25}  |  {bisec[i*2 + 1]:<25}")
print("-------------------------------------------------------------------------------------------")
