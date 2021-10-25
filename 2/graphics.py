from matplotlib import pyplot as plt  # -0.5, 0.5, 4.5
import numpy as np

a = 0  # int(input("a = "))
b = 1  # int(input("b = "))
c = -3  # int(input("c = "))

C = [3**0.5 - 4]  # ,-5,-4,0,1,2,3,4,5,6.5,7,8.5,10]
# -7,-5.5, 0, 2.5, 4
for c in C:

    # circle 1 period
    x = np.linspace(0, 2*b, 1000)
    y = -(4*(b**2) - x**2)**0.5 + b
    plt.plot(x, y, 'r')

    # lines 1 period
    plt.plot([2*b, c, 4*b], [b, a, -b], 'r')

    # circle 2 period
    x = np.linspace(0, 2*b, 1000)
    y = -(4*(b**2) - x**2)**0.5 + b
    plt.plot(x + 4*b, y, 'r')

    # lines 2 period
    plt.plot([6*b, c + 4*b, 8*b], [b, a, -b], 'r')

    # Ox
    plt.plot(np.linspace(-100, 100, 100), [0]*100, 'black')

    plt.xlim(-5, 10)
    plt.ylim(-2, 2)
    plt.grid(True)

    plt.title('a = '+str(a)+' b = '+str(b)+' c = '+str(c))

    plt.show()
