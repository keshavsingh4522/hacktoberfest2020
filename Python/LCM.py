'''
Finding LCM of given two numbers
'''


def calculate_lcm(x, y):
    if x > y:
        gr = x
    else:
        gr = y
    while(True):
        if((gr % x == 0) and (gr % y == 0)):
            lcm = gr
            break
        gr += 1
    return lcm
