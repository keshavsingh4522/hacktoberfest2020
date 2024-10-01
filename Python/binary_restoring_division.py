def deci_to_bin(n):
    return bin(n).replace("0b", "")

def shift_left(C,AC,Q):
    
    C=AC[0]
    
    temp_AC=list(AC)
    for i in range(1,len(AC)):
        temp_AC[i-1]=temp_AC[i]
    temp_AC[len(AC)-1]=Q[0]
    AC=''
    AC=AC.join(temp_AC)

    temp_Q=list(Q)
    for i in range(1,len(Q)):
        temp_Q[i-1]=temp_Q[i]
    temp_Q[len(Q)-1]='_'
    Q=''
    Q=Q.join(temp_Q)
    
    return(C,AC,Q)

def operation(C,AC,M):
    temp=C+AC
    temp=bin(int(temp,2)+int(M,2))
    temp=temp.replace("0b","")

    # discard the carry while operation is done
    if(len(temp)>len(M)):
        temp=temp[1::]
    return(temp[0],temp[1::])


# Main function
AC=''
C='0'

Q=input("Enter the dividend(Q)  :  ")
Q=deci_to_bin(int(Q))

M=input("Enter the divisor(M)   :  ")
M=deci_to_bin(int(M))

if(len(Q)>len(M)):
    for i in range(len(Q)):
        AC=AC+'0'
else:
    for i in range(len(M)):
        AC=AC+'0'
print("Initial C value is     : ",C)
print("Initial AC value is    : ",AC)
print("Initial Q value is     : ",Q)

for i in range(len(Q)-len(M)):
    M='0'+M
# adding one bit extra
M='0'+M
print("Value of M is          : ",M)

# two's complement
M_array=list(M)
for i in range(len(M)):
    if(M[i]=='0'):
        M_array[i]='1'
    if(M[i]=='1'):
        M_array[i]='0'
M_negative=''
M_negative=M_negative.join(M_array)
M_negative=bin(int(M_negative,2)+int('1',2))
M_negative=M_negative.replace("0b","")
print("Two's complement of M  : ",M_negative)
print()

print("---------------------------------------------------------------------------------------------------------------------")
print("\t C "," "*int(len(AC)/2),"AC"," "*int(len(AC)/2)," "*int(len(Q)/2),"Q"," "*int(len(Q)/2),"     Operation done")
print("---------------------------------------------------------------------------------------------------------------------")
print("\t",C,"  ",AC,"  ",Q,"   ","Initial values")
print()

      
for i in range(len(Q)):
    print("step",(i+1),":  ")
    C,AC,Q=shift_left(C,AC,Q)

    print("\t",C,"  ",AC,"  ",Q,"   ","After shift left operation")

    C,AC=operation(C,AC,M_negative)
    print("\t",C,"  ",AC,"  ",Q,"   ","AC_equals_AC_minus_M operation")
    
    if(C=='1'):
        temp_Q=list(Q)
        temp_Q[len(Q)-1]='0'
        Q=''
        Q=Q.join(temp_Q)
        
        C,AC=operation(C,AC,M)
        print("\t",C,"  ",AC,"  ",Q,"   ","AC_equals_AC_plus_M operation")
        
    else:
        temp_Q=list(Q)
        temp_Q[len(Q)-1]='1'
        Q=''
        Q=Q.join(temp_Q)
    print()
    
print('\nFinal values')    
print("\t",C,"  ",AC,"  ",Q)
print()
print("Remainder=(C,AC)       : ",int(C+AC,2))
print("Quotient=(Q)           : ",int(Q,2))