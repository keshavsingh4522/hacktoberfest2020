#DIVISION RESTORING ALGORITHM

#CONVERTS DECIMAL TO BINARY
def binary(a):  #converts decimal to binary
	bits_list=[]
	
	while(a>0):
		num=a
		b=int(num%2)
		bits_list.append(b)
		num=num//2
		a=int(a/2)
	#print(bits_list)
	bits_list.reverse()
	return bits_list;

#LEFT SHIFT OPERATION
def Shift(shiftA,shiftQ):

	val=shiftA+shiftQ
	l = len(val)
	i=0

	'''while(i<l-1):
		val[i]=val[i+1]
		i=i+1
	val[i]=0
	return val
'''
	for i in range(0,l-1):
		val[i]=0
		val[i]=val[i+1]
	del val[i]
	return val

#TAKES 2's COMPLIMENT (REQD FOR "-M")
def compliment(value):
	onecomp = []
	twocomp = []
	for i in range(0,len(value)):
		if value[i]==0:
			onecomp.append(1)
		elif value[i]==1:
			onecomp.append(0)
	
	carry=1
	for j in range(len(value)-1,-1,-1):
		
		if(onecomp[j]==0 and carry==1):
			twocomp.append(1)
			carry=0
		elif(onecomp[j]==1 and carry==1):
			twocomp.append(0)
			carry=1
		elif(onecomp[j]==0 and carry==0):
			twocomp.append(0)
			carry=0
		elif(onecomp[j]==1 and carry==0):
			twocomp.append(1)
			carry=0
	twocomp.reverse()
	return twocomp
	
#ADDING TWO BINARY NOS.
def Add(valA,valM):
	add = []
	ad = valA
	carry = 0
	for i in range(len(ad)-1,-1,-1):
		if(valA[i]==0 and valM[i]==0 and carry==0):
			add.append(0)
			carry=0
		elif(valA[i]==0 and valM[i]==0 and carry==1):
			add.append(1)
			carry=0
		elif(valA[i]==0 and valM[i]==1 and carry==0):
			add.append(1)
			carry=0
		elif(valA[i]==0 and valM[i]==1 and carry==1):
			add.append(0)
			carry=1
		elif(valA[i]==1 and valM[i]==0 and carry==0):
			add.append(1)
			carry=0
		elif(valA[i]==1 and valM[i]==0 and carry==1):
			add.append(0)
			carry=1
		elif(valA[i]==1 and valM[i]==1 and carry==0):
			add.append(0)
			carry=1
		elif(valA[i]==1 and valM[i]==1 and carry==1):
			add.append(1)
			carry=1
	add.reverse()
	return add

#CONVERTS BINARY TO DECIMAL
def decimal(bin):
	bin.reverse()
	dec=0
	for i in range(0,len(bin)):
		if(bin[i]==1):
			dec=dec+(bin[i](2*i))
		elif(bin[i]==0):
			pass
	bin.reverse()
	return dec



print("      DIVISION RESTORING ALGORITHM     ")
print("")
dividend=int(input("Enter value of Dividend -> Q : "))
divisor=int(input("Enter value of Divisor -> M : "))
print("")
print("")

q=binary(dividend)
m=binary(divisor)

print("Q : ",*q)

#SETTING THE M VALUE : i.e. len(M) should be 1 more than len(Q)
if len(m) < len(q):
	diff=len(q)-len(m)
	for i in range(0,diff+1):
		m.insert(0,0)
print("M : ",*m)



#ASSIGNING VALUE OF A to 0
ACC = []
for i in range(0,len(m)):
	ACC.append(0)
print("A : ",*ACC)

#VALUE OF -M
negM = compliment(m)
print("-M : ",*negM)
print("")

"""
#LEFT SHIFT A, Q
a = Shift(ACC,q)
print(*a)
#TAKING THE "A" part from the AQ 
newA=a[0:len(ACC)]
print(*newA)
""" #Ignore this comment

print("          ","    |   ","   A    ","    |    ","   Q  ","    |    ")
print("--------------------------------------------------------")
n=1
#No of iterations
counter = len(q)
while counter > 0:

	
	#LEFT SHIFT A, Q
	a = Shift(ACC,q)
	#print(*a)

	#TAKING THE "A" AND "Q" PART FROM THE "a"
	newA=a[0:len(ACC)]
	newQ=a[len(ACC):]
	#print(*newA)
	#print(*newQ)

	#A<-A-M
	sumAM = Add(newA,negM)
	#print(*sumAM)


	b=len(newQ)+1
	if(sumAM[0]==1):#MSB(A)=1
		newQ.insert(b,0)
		sumAM=Add(sumAM,m)
	elif(sumAM[0]==0):#MSB(A)=0
		newQ.insert(b,1)

	ACC=sumAM
	q=newQ

	print("Step : ",n,"    |    ",*ACC,"    |    ",*q,"  |  ")

	print("--------------------------------------------------")
	n=n+1
	counter=counter-1

print("Quotient: ",*q,"  ->  ",decimal(q))
print("Remainder: ",*ACC,"  ->  ",decimal(ACC))