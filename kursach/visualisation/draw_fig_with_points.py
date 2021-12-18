import sys
import matplotlib.pyplot as plt
import numpy as np
from math import pi, cos, sin


def get_distance(one,two):
    return ((one[0]-two[0])**2 + (one[1]-two[1])**2)**0.5


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

xs = []
ys = []
for i in range(1,11):
    if i%2 == 1:
        xs.append(float(sys.argv[i]))
    elif i%2 == 0:
        ys.append(float(sys.argv[i]))
xs.append(float(sys.argv[1]))
ys.append(float(sys.argv[2]))

plt.plot(xs,ys, 'ro')
plt.plot([xs[0],xs[4]],[ys[0],ys[4]],'b')
plt.plot([xs[2],xs[3]],[ys[2],ys[3]],'b')

r = abs(get_distance([xs[0], ys[0]],[xs[1],ys[1]]))
t = np.linspace(0,pi*2,100)
y = [r*sin(i)+ys[1] for i in t]
x = [r*cos(i)+xs[1] for i in t]
plt.plot(x,y,'b')

c2 = [(xs[3]+xs[4])/2, (ys[3]+ys[4])/2]
y = [r*sin(i)+c2[1] for i in t]
x = [r*cos(i)+c2[0] for i in t]
plt.plot(x,y,'b')


plt.gca().set_aspect('equal', adjustable='box')
plt.show()