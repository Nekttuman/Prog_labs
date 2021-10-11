from math import factorial as fact
import matplotlib.pyplot as plt

def print_gr(x):
    x = -3 #int(input("x = "))
    l = []
    for k in range(1,12):
        a = pow(3,k)/(pow(4,k)*fact(k+2))*pow(x,k)
        l.append(a)

    print(l)

    k = [1,2,3,4,5,6,7,8,9,10,11]
    plt.plot(k,l,k,l,'ro')
    plt.title("x = "+str(x))
    plt.xlabel('k')
    plt.show()

print_gr(-3)
print_gr(-0.5)
print_gr(0.5)
print_gr(2)
