import fixedPointIteration as fp
import bisection as bi
import math
import sys
import inspect


def f(x):
    return 10.14*(((math.e)**x)**2)*math.cos(math.pi/x)


def g(x):
    return x - f(x)


tol = input("Enter a value for tol: ")
maxIter = input("Enter a value for maxIter: ")

x0_array = []
for i in range(-30, 71):
    if i != 0:
        x0_array.append(.1*i)

fixed = []
for x0 in x0_array:
    fixed += fp.fixedPointIter(inspect.getsource(g), x0, tol, maxIter, 0)


print("\nIf the full table is not requested, the final iteration will show as iteration 0\n")

print("----Fixed Point Iteration------------------------------------------------------------------")
print("x0 |             x               |            f(x)             |      Error  ")
print("-------------------------------------------------------------------------------------------")
for i in range(0, int(len(fixed)/2)):
    print(f"{round(x0_array[i], 1):>5}  |  {fixed[i*2]:<25}  |  {f(fixed[i*2]):<25}  |  {fixed[i*2 + 1]:<25}")
print("-------------------------------------------------------------------------------------------")
