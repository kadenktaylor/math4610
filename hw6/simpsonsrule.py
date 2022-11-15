import math

a = 0
b = 1
n = [8, ]  # 16, 32, 64, 128, 256, 512, 1024, 2048]


def f(x):
    return ((x**4)*((1-x)**4)) / (1 + (x**2))


def simpson(f, a, b, n):
    h=(b-a)/n
    k=0.0
    x=a + h
    for i in range(1, n//2 + 1):
        k += 4*f(x)
        x += 2*h

    x = a + 2*h
    for i in range(1, n//2):
        k += 2*f(x)
        x += 2*h
    return (h/3)*(f(a)+f(b)+k)


print("------------ pi ----------------")
for i in range(0, len(n)):
    print(f"n = {n[i]}, approximation = {simpson(f, a, b, n[i])}")
