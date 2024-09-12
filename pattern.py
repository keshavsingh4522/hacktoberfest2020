number_rows=int(input("number of rows="))
number_columns=int(input("number of columns="))
k=0
for i in range(1,number_rows+1):
    if(k<4):
        k=k+1
    else:
        k=k-1
    for j in range(1,number_columns+1):
        if (j<=k):
            print("*",end=" ")
        else:
            print(" ",end=" ")
    print( )
        

