# -*- coding: utf-8 -*-
"""
Created on Sun Feb  7 15:00:36 2021

@author: belimeio
"""

x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
for i in x:
    print(i)
    
i=0
while  i<10:
    print(i)
    i+=1
    
for i in range(4, 100, 3):
    print(i)
else:
    print(i)
    
x = ['big', 'small', 'bold', 'light', 'heavy']
y = ['iron', 'silver', 'gold', 'platinum', 'diamond']
for i in x:
    for j in y:
        print(i,j)
