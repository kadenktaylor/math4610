h = .1
a = 2.0
b = .0005
P0 = 10.0
P = P0
end_t = 100


def dPdt(a, b, P):
    return a*P - b*P*P


for i in range(0, int(end_t/h)):
    P1 = P + h*dPdt(a, b, P)
    P = P1
    print(f"P = {P}")
