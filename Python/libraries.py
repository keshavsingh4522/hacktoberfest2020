# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 10:31:26 2021

@author: belimeio
"""

import numpy as np
import matplotlib.pyplot as plt

x = [[1,2,3],[4,5,6],[7,8,9]]
a = np.array(x)
print(a)

%matplotlib inline
x = np.linspace(0,10,100)
y = x**2
plt.plot(x,y)