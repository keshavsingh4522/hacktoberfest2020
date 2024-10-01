def d_to_b_converter(n):

    if(n > 1):   #check if number is greator than 1 or not
        d_to_b_converter(n//2)   #recursively sending dividend
    print(n%2, end=' ') #printing remainder

n= int(input("Enter your number"))
d_to_b_converter(n)
