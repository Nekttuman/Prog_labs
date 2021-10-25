from matplotlib import pyplot as plt  # -0.5, 0.5, 4.5
import numpy as np

inp_x = float(input("x = "))
inp_y = float(input("y = "))

a = 0  # int(input("a = "))
b = 1  # int(input("b = "))
c = -5  # int(input("c = "))

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

plt.grid(True)
plt.title('a = '+str(a)+' b = '+str(b)+' c = '+str(c))

plt.plot(inp_x, inp_y, 'bo')



import os
os.system('"D:/repos/Prog_labs/2/lab2/Debug/lab2.exe"')

plt.show()