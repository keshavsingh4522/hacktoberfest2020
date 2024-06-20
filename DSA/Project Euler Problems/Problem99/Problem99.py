import math

f = open("p099_base_exp.txt",'r')
curr = 0
linenumber = 0
for index,elem in enumerate(f.readlines()):
    base = int(elem.split(',')[0])
    exp = int(elem.split(',')[1][:-1])
    if exp*math.log(base) > curr:
        curr = exp*math.log(base)
        linenumber = index
print(curr,linenumber + 1)