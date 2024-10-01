# -*- coding: utf-8 -*-
"""
Created on Mon Feb  8 10:51:08 2021

@author: belimeio
"""

import json

x = {'name':'alex', 'age':32, 'job':'developer'}
y = json.dumps(x)
print(y)

z = json.loads(y)
print(z)