import matplotlib.pyplot as plt
import numpy as np
from math import pi, cos, sin


f = open('../input.txt')
xs = [2,2,5,5, 2]
ys = [1, 4,1,4, 2.5]

plt.plot(xs,ys,'ro')

plt.plot([2,5],[1,1],'b')
plt.plot([2,5],[4,4],'b')

r = 1.5
t = np.linspace(pi/2, pi*1.5 , 100)
y = [r * sin(i) + 2.5 for i in t]
x = [r * cos(i) + 2 for i in t]
plt.plot(x, y, 'b')

t = np.linspace(-pi/2, pi/2 , 100)
y = [r * sin(i) + 2.5 for i in t]
x = [r * cos(i) + 5 for i in t]
plt.plot(x, y, 'b')



plt.grid(True)
plt.gca().set_aspect('equal', adjustable='box')
plt.show()


# посчитать, сколько вершин входят в фигуру

# сравнить с предыдущим максимумом



