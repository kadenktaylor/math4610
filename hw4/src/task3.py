x = [1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0]
y = [.5, 1.0, 1.5, 2.0, 3.0, 3.0, 3.5, 4.5, 5.0, 5.5]

n = len(x)

a11 = n + 1
a12 = x[0]
a22 = x[0] ** 2
b1 = y[0]
b2 = x[0] * y[0]
for i in range(1, n):
    a12 = a12 + x[i]
    a22 = a22 + (x[i] ** 2)
    b1 = b1 + y[i]
    b2 = b2 + (x[i] * y[i])
a21 = a12

detA = (a11 * a22) - (a12 * a21)
b = ((a22 * b1) - (a12*b2)) / detA
a = ((a11 * b2) - (a21 * b1)) / detA

print(f"The value of a is: {a} \nThe value of b is: {b} \nThe equation is: {a}x + {b}")