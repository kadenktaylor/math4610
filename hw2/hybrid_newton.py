import math


def hybrid_newton(f, df, a, b, tol, maxIter):
    error = 10.0*tol
    iteration = 0
    x0 = .5*(a+b)
    while error > tol and iteration < maxIter:
        x1 = x0 - f(x0)/df(x0)
        newton_error = abs(x1 - x0)
        if newton_error > error:
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
            x0 = .5*(a + b)
        else:
            print("Newton Iteration")
            x0 = x1
            error = newton_error
        iteration = iteration + 1
    return x0


f = lambda x: x*math.e**(-x)
df = lambda x: math.e**(-x) - (x * math.e**(-x))

print(f"Hybrid Newton Method: {hybrid_newton(f, df, -200.0, 1000, .0001, 20)}")