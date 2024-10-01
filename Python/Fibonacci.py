def Fibonacci(n):

    if n < 0: 
        print("Incorrect Input") 
		
    elif n == 0:  		## if n==0 then Function will return 0 ,i.e. as the series starts with 0,1
        return 0
 
    elif n == 1 or n == 2:  ## if the value of n is 1 or 2 then fuction return 1 ,i.e. n==2 the series will be 0 1 1  
        return 1
 
    else:      				## if n>2 then it perfrom some calculation in recurrsion
        return Fibonacci(n-1) + Fibonacci(n-2)
		
print(Fibonacci(int(input()))
