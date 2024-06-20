def number_of_ways(denominations, m, total_amount ): 
	if (total_amount == 0): 
		return 1

	if (total_amount < 0): 
		return 0

	if (m <=0 and total_amount >= 1): 
		return 0
        
	return number_of_ways( denominations, m - 1, total_amount ) + number_of_ways( denominations, m, total_amount-denominations[m-1] ); 


arr = [1, 2, 5, 10, 20, 50, 100, 200] 
m = len(arr) 
print(number_of_ways(arr, m, 200)) 

