# Software Manual: Secant Method

**Routine Name:** secant.py

**Author:** Kaden Taylor

**Language:** python 3.9

**Description/Purpose:** This program will a given function and estimate a root for the function when two given initial guesses.

**Input:** f = function, x0 = an array with 2 elements in it, the first and second guesses, tol = tolerance (level of precession), v = flag of whether to return a single (v = 0) result or a full table (v = 1)

**Output:** This method returns an array. Depending on the v flag input, the last iteration may be the only element in the array or the array may have each iteration in it.

**Usage/Example:**
The code is tested with the function, `f(x) = x*math.e**-x`

The command line entry looks like this:
```
$ python rootfinding.py x*math.e**-x math.e**-x-x*math.e**-x x-x*math.e**-x -2 1 .1 .2 .000001 20 1
```

The output for the Secant method is here:
```
----------Secant------------------------------------------------------------------------
iter |             x               |            f(x)             |      |Error|
-------------------------------------------------------------------------------------------
  0  |  0.2                        |  0.1637461506155964         |  0.1
  1  |  -0.023506370143776475      |  -0.024065464982500492      |  0.2235063701437765
  2  |  0.005132884712382435       |  0.005106605708157981       |  0.02863925485615891
  3  |  0.00011954905045136535     |  0.00011953475933016354     |  0.00501333566193107
  4  |  -6.152459741965571e-07     |  -6.152463527242824e-07     |  0.00012016429642556191
-------------------------------------------------------------------------------------------
```


**Implementation/Code:** The following is the code for secant()
```python
import math as math


def secant(f, x0, tol, v):
    if v == 0:
        if abs(f(x0[-1])) < tol:
            return x0
        else:
            x0_next = x0[-2] - ((x0[-1]-x0[-2]) * f(x0[-2])) / (f(x0[-1]) - f(x0[-2]))
            x0[-2] = x0[-1]
            x0[-1] = x0_next
            return secant(f, x0, tol, 0)
    else:
        if abs(f(x0[-1])) < tol:
            return x0
        else:
            x0_next = x0[-2] - ((x0[-1]-x0[-2]) * f(x0[-2])) / (f(x0[-1]) - f(x0[-2]))
            x0.append(x0_next)
            return secant(f, x0, tol, 1)


```

Here is the code for the rootfinding.py:
```python
import fixedPointIteration as fp
import bisection as bi
import newton as newton
import secant as secant
import hybrid_newton as hybrid_newton
import hybrid_secant as hybrid_secant
import math
import sys

if len(sys.argv) > 8:
    f_expression = sys.argv[1]
    df_expression = sys.argv[2]
    g_expression = sys.argv[3]
    a = sys.argv[4]
    b = sys.argv[5]
    x0 = sys.argv[6]
    x1 = sys.argv[7]
    tol = sys.argv[8]
    maxIter = sys.argv[9]
    v = sys.argv[10]
else:
    print("Don't add any parenthesis to the equations")
    f_expression = input("Enter a value for f(x) = ")
    df_expression = input("Enter a value for f'(x) = ")
    g_expression = input("Enter a value for g(x) = ")
    a = input("Enter a value for a = ")
    b = input("Enter a value for b = ")
    x0 = input("Enter a value for x0: ")
    x1 = input("Enter a value for x1: ")
    tol = input("Enter a value for tol: ")
    maxIter = input("Enter a value for maxIter: ")
    v = input("Print full table? 1 = Yes, 0 = No: ")

f = lambda x: eval(f_expression)
df = lambda x: eval(df_expression)
g = lambda x: eval(g_expression)
a = float(a)
b = float(b)
x0 = float(x0)
x1 = float(x1)
tol = float(tol)
maxIter = int(maxIter)
v = int(v)

fixed = fp.fixedPointIter(g, x0, tol, maxIter, v)
bisec = bi.bisection(f, a, b, tol, maxIter, v)

x0_array = [x0]
newt = newton.newton(f, df, x0_array, tol, v)

x0_array = [x0, x1]
sec = secant.secant(f, x0_array, tol, v)

hnewt = hybrid_newton.hybrid_newton(f, df, a, b, tol, maxIter, v)
hsec = hybrid_secant.hybrid_secant(f, a, b, tol, maxIter,v)

print("\nIf the full table is not requested, the final iteration will show as iteration 0\n")

print("----Fixed Point Iteration------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      |Error|  ")
print("-------------------------------------------------------------------------------------------")
for i in range(0, int(len(fixed)/2)):
    print(f"{i:>3}  |  {fixed[i*2]:<25}  |  {f(fixed[i*2]):<25}  |  {fixed[i*2 + 1]:<25}")
print("-------------------------------------------------------------------------------------------\n\n")

print("----------Bisection------------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      |Error|  ")
print("-------------------------------------------------------------------------------------------")
for i in range(0, int(len(bisec)/2)):
    print(f"{i:>3}  |  {bisec[i*2]:<25}  |  {f(bisec[i*2]):<25}  |  {bisec[i*2 + 1]:<25}")
print("-------------------------------------------------------------------------------------------\n\n")

if len(newt) < 2:
    newt.append(newt[0])

print("----------Newton------------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      |Error|  ")
print("-------------------------------------------------------------------------------------------")
for i in range(1, len(newt)):
    print(f"{i-1:>3}  |  {newt[i]:<25}  |  {f(newt[i]):<25}  |  {(abs(newt[i] - newt[i-1])):<25}")
print("-------------------------------------------------------------------------------------------\n\n")

print("----------Secant------------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      |Error|  ")
print("-------------------------------------------------------------------------------------------")
for i in range(1, len(sec)):
    print(f"{i-1:>3}  |  {sec[i]:<25}  |  {f(sec[i]):<25}  |  {(abs(sec[i] - sec[i-1])):<25}")
print("-------------------------------------------------------------------------------------------\n\n")

print("----------Hybrid Newton------------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      |Error|  ")
print("-------------------------------------------------------------------------------------------")
for i in range(0, int(len(hnewt)/2)):
    print(f"{i:>3}  |  {hnewt[i*2]:<25}  |  {f(hnewt[i*2]):<25}  |  {hnewt[i*2 + 1]:<25}")
print("-------------------------------------------------------------------------------------------\n\n")

print("----------Hybrid Secant------------------------------------------------------------------------")
print("iter |             x               |            f(x)             |      |Error|  ")
print("-------------------------------------------------------------------------------------------")
for i in range(0, int(len(hsec)/2)):
    print(f"{i:>3}  |  {hsec[i*2]:<25}  |  {f(hsec[i*2]):<25}  |  {hsec[i*2 + 1]:<25}")
print("-------------------------------------------------------------------------------------------\n\n")
```
 
