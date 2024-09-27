# Python3 program to find simple interest 
# for given principal amount, time and 
# rate of interest. 


def simple_interest(p,t,r): 
	print('The principal is', p) 
	print('The time period is', t) 
	print('The rate of interest is',r) 
	
	si = (p * t * r)/100
	
	print('The Simple Interest is', si) 
	return si 
	
# Driver code 
simple_interest(8, 6, 8) 

#accepting user values for p,t,r
p=double(input())
t=double(input())
r=double(input())

simple_interest(p,t,r)
