from math import sin, cos, pi
import numpy as np 


class F:
    def __init__(self, n, m):
        self._n = n
        self._m = m
        
    def __call__(self, x):
        f = lambda x: sin(self._n*x) * cos(self._m*x)
        return (f(x))
        
        
u = F(1, 3)
v = F(4, 6)

x_u = np.linspace(0, 2*pi, 1000)
x_v = np.linspace(0, 2*pi, 1000)

i = 0

for x_value in x_u:
    x_u[i] = u.__call__(x_value)
    i += 1

k = 0 
  
for x_value in x_v:
    x_v[k] = v.__call__(x_value)
    k += 1

plt.plot(x_u, x_v)
