import numpy as np
import matplotlib.pyplot as plt

class EDE:
    def __init__(self, dy_dx, p):
        self.dy_dx = dy_dx
        self.p = p

    def y(self, x, del_x = 0.001):
        _x = self.p[0]
        _y = self.p[1]

        if _x > x:
            dir = -1
        else:
            dir = 1

        while round(_x, 3) != x:
            _y = _y + self.dy_dx(_x, _y) * del_x
            _x += dir * del_x
            print(f"{_x=}")
            print(f"{_y=}")

        return _y


def dy_dx(x, y):
    return x**2

ede = EDE(dy_dx, [-10, -1000/3])

# y = 1/3 * x**3
def y(x):
    return (x ** 3) / 3

x = np.arange(-10, 10)
plt.plot(x, y(x))

xlist = range(-10, 10)
ylist = []
for i in xlist:
    ylist.append(ede.y(i, del_x = 0.01))
plt.plot(xlist, ylist)

plt.plot(x, dy_dx(x, 0))

plt.plot([-10], [-1000/3], marker="o")
plt.show()
