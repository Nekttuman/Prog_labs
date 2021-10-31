from matplotlib import pyplot as plt  # -0.5, 0.5, 4.5
import numpy as np
import os

a = float(input("a = "))
b = float(input("b = "))
c = float(input("c = "))

inp_x = float(input("x = "))
inp_y = float(input("y = "))


def plot_graphic(a,b,c,x,y):
    # circle 1 period
    x = np.linspace(0, 2*b, 1000)
    if b>=0:
      y = -(4*(b**2) - x**2)**0.5 + b
    else:
      y = (4*(b**2) - x**2)**0.5 + b
    plt.plot(x, y, 'r')
    # lines 1 period
    plt.plot([2*b, c, 4*b], [b, a, -b], 'r')
    # circle 2 period
    plt.plot(x + 4*b, y, 'r')
    # lines 2 period
    plt.plot([6*b, c + 4*b, 8*b], [b, a, -b], 'r')

    plt.plot([min(0,8*b, c, c+4*b) -1, max(0,8*b, c, c+4*b) + 1],[0,0], 'black')

    plt.grid(True)
    plt.title('a = '+str(a)+' b = '+str(b)+' c = '+str(c))

    plt.plot(inp_x, inp_y, 'bo')
    plt.show()


plot_graphic(a,b,c,inp_x,inp_y)
os.system(f'"D:/repos/Prog_labs/2/lab2/Debug/lab2.exe "{a}" "{b}" "{c}" "{inp_x}" "{inp_y}""')

ans = int(input("\n\n(1) - Продолжить с новыми значениями параметров\n(2) - изменить только xy\n(3) - завершить\n"))

while ans != 3:
    if ans == 1:

        a = float(input("a = "))
        b = float(input("b = "))
        c = float(input("c = "))

        inp_x = float(input("x = "))
        inp_y = float(input("y = "))

        plot_graphic(a,b,c,inp_x,inp_y)
        os.system(f'"D:/repos/Prog_labs/2/lab2/Debug/lab2.exe "{a}" "{b}" "{c}" "{inp_x}" "{inp_y}""')

        ans = int(input("\n\n(1) - Продолжить с новыми значениями параметров\n(2) - изменить только xy\n(3) - завершить\n"))

    elif ans == 2:
        inp_x = float(input("x = "))
        inp_y = float(input("y = "))

        plot_graphic(a,b,c,inp_x,inp_y)
        os.system(f'"D:/repos/Prog_labs/2/lab2/Debug/lab2.exe "{a}" "{b}" "{c}" "{inp_x}" "{inp_y}""')

        ans = int(input("\n\n(1) - Продолжить с новыми значениями параметров\n(2) - изменить только xy\n(3) - завершить\n"))
    else:
        print("неверный ввод")
        ans = int(input("\n\n(1) - Продолжить с новыми значениями параметров\n(2) - изменить только xy\n(3) - завершить\n"))
