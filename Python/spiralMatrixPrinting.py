def spiralMatrix(n):
	'''
	Printing an array matrix of size n, with numbers from 1 to n^2 spirally inwards
	'''
	arr = []
	for i in range(n):
		new = []
		for j in range(n):
			new.append(-1)
		arr.append(new)

	count = 1
	k,l = 0,0
	m = n
	while(l < n and k < m):
		for i in range(l,n):
			arr[k][i] = count
			count += 1
			# print(count)
		k += 1
		for i in range(k,m):
			arr[i][n-1] = count
			count += 1
			# print(count)
		n -= 1
		if k < m:
			for i in range(n-1,l-1,-1):
				arr[m-1][i] = count
				count += 1
				# print(count)
			m -= 1
		if l < n:
			for i in range(m-1,k-1,-1):
				arr[i][l] = count
				count += 1
				# print(count)
			l += 1
	return arr

arr = spiralMatrix(4)
for i in arr:
 	print(i)

# Output:
# [1, 2, 3, 4]
# [12, 13, 14, 5]
# [11, 16, 15, 6]
# [10, 9, 8, 7]
