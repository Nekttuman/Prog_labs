import matplotlib.pyplot as plt
import numpy as np

f = open('D:/repos/Prog_labs/kursach/input.txt')
xs = []
ys = []
x, y = [float(i) for i in f.readline().split()]
xs.append(x)
ys.append(y)
while True:
    inp = f.readline()
    if not inp:
        break
    if inp != "\n":
        x, y = [float(i) for i in inp.split()]
    xs.append(x)
    ys.append(y)


plt.grid(True)
plt.plot(xs, ys, 'yo')

plt.show()
