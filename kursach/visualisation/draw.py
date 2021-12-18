import matplotlib.pyplot as plt
import numpy as np
from math import pi, cos, sin


f = open('../input.txt')
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


n = len(xs)
def get_distance(one,two):
    return ((one[0]-two[0])**2 + (one[1]-two[1])**2)**0.5

def is_equival(one,two):
    return (one[0] == two[0] and one[1]==two[1])

def preplot():
    plt.grid(True)
    plt.plot(xs, ys, 'yo')


max_points_count = 0
max_points_fig = 0
# найти два равных отрезка лежащих на одной прямой и имеющих общюю вершину
for one in range(n-2):
    for two in range(one+1, n-1):
        d12 = get_distance([xs[one],ys[one]],[xs[two],ys[two]])
        for three in range(two+1, n):
            d23 = get_distance([xs[three],ys[three]],[xs[two],ys[two]])
            if (xs[three] - xs[one])*(ys[two] - ys[one]) == (ys[three] - ys[one])*(xs[two] - xs[one]) and \
                (d12 == d23 or d12 == 0.5*d23 or d23 == 0.5*d12) :
                if d23 == 0.5 *d12:
                    fig = [[xs[one],ys[one]],[xs[three],ys[three]],[xs[two],ys[two]]]
                elif d23 == d12:
                    fig = [[xs[one],ys[one]],[xs[two],ys[two]],[xs[three],ys[three]]]
                else:
                    fig = [[xs[two],ys[two]],[xs[one],ys[one]],[xs[three],ys[three]]]
                fig_ = fig
            # проверить, есть ли вершины, образующие с данными прямоугольник
                for four in range(n-1):
                    for five in range(four+1,n):   
                        if is_equival(fig[0], [xs[four],ys[four]]) or is_equival(fig[0], [xs[five],ys[five]]) or\
                            is_equival(fig[2], [xs[four],ys[four]]) or is_equival(fig[2], [xs[five],ys[five]]) or\
                                get_distance(fig[0], fig[2]) != get_distance([xs[four],ys[four]], [xs[five],ys[five]]):
                            continue
                        if get_distance(fig[0], [xs[five],ys[five]]) < get_distance(fig[2], [xs[five],ys[five]]):
                            five_p = [xs[five], ys[five]]
                            four_p = [xs[four],ys[four]]
                        else:
                            five_p = [xs[four],ys[four]]
                            four_p = [xs[five], ys[five]]
                        center = [(fig[0][0]+four_p[0])/2, (fig[0][1]+four_p[1])/2]
                        if get_distance(center, fig[0]) == get_distance(center, five_p):
                            fig.append(four_p)
                            fig.append(five_p)
                            c2 = [(fig[3][0]+fig[4][0])/2, (fig[3][1]+fig[4][1])/2]
                            print(*fig)

                            # нарисовать фигуру
                            preplot()
                            x_s = [p[0] for p in fig]
                            y_s = [p[1] for p in fig]
                            plt.plot(x_s,y_s, 'ro')
                            plt.plot([x_s[0],x_s[4]],[y_s[0],y_s[4]],'b')
                            plt.plot([x_s[2],x_s[3]],[y_s[2],y_s[3]],'b')
                            r = get_distance(fig[0],fig[1])
                            t = np.linspace(0,pi*2,100)
                            y = [r*sin(i)+fig[1][1] for i in t]
                            x = [r*cos(i)+fig[1][0] for i in t]
                            plt.plot(x,y,'b')
                            plt.plot(c2[0],c2[1],'go')
                            y = [r*sin(i)+c2[1] for i in t]
                            x = [r*cos(i)+c2[0] for i in t]
                            plt.plot(x,y,'b')
                            plt.gca().set_aspect('equal', adjustable='box')
                            plt.show()
                        fig = fig_
             


# посчитать, сколько вершин входят в фигуру

# сравнить с предыдущим максимумом



