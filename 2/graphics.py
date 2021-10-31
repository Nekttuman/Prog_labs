from matplotlib import pyplot as plt  # -0.5, 0.5, 4.5
import numpy as np

def line3(x, a, b, c):
  y = (x - 6 * b) * (a - b) / (c - 2 * b) + b
  return y

def line4(x, a, b, c):
  if (4 * b != c):
    y = (x - c - 4 * b) * (b - abs(2 * b)-a) / (4 * b - c) + a
    return y
  else:
    return 8 * b

a = 2  # int(input("a = "))
b = 1  # int(input("b = "))
c = a + 5*b +1  # int(input("c = "))

def plot(a,b,c):
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

    plt.plot([min(0,8*b) -1, max(0, 8*b) + 1],[0,0], 'black')

    x = (-a)*(4*b-c)/(-a-b) + c
    plt.plot([x],[0],'bo')

    plt.grid(True)
    plt.title('a = '+str(a)+' b = '+str(b)+' c = '+str(c))
    plt.show()

plot(a,b,c)


# plot(-1.5,-1,-3)

# a = 3
# b = 1
# c = 8
# x = 5.5
# y = 0.3