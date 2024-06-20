import time


def calcTimeDecorator(funcToWrap): # decorator
    # Wraps original function with a timing decorator 
    # executes time.time() before and after executing decorated function
    # decorated function still returns it's original result
    def originalFuncWrapper(*args, **kwargs): 
        # *args and **kwargs to pass each argument that was passed into original function
        start = time.time()
        res = funcToWrap(*args, **kwargs)  
        finish = time.time()
        
        calcTime = finish - start
        print(f"Execution time of {funcToWrap.__name__} : {calcTime} s. Result: {res}")

        # return original result of the decorated function
        return res 

    # return originalFuncWrapper function to EXECUTE it, otherwise it won't be executed    
    return originalFuncWrapper 

"""
 @decorator
 def func() 
 
 is the same as:
 
 decorated_func = decorator(funcToWrap)
 decorated_func()
"""

# Execution time of 3 factorial variants
def facRec(x): # recursion method 
    if x == 1:
        return x
    else:
        return x * facRec(x-1)

@calcTimeDecorator
def facRecAll(x): # prevent from calling decorator multiple times
    return facRec(x)

@calcTimeDecorator
def facWhl(x): # while loop method
    res = 1
    i = 1
    while i <= x:
        res = res * i
        i += 1
    return res


@calcTimeDecorator
def facFor(x): # for loop method
    res = 1
    for i in range(1, x+1):
        res = res*i
    return res


facRecAll(5)
facFor(5)
facWhl(5)
