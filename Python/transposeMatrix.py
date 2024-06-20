# Define a matrix A  
A = [[5, 4, 3],  
         [2, 4, 6],  
         [4, 7, 9],  
         [8, 1, 3]]  
# Define an empty matrix of reverse order  
transResult = [[0, 0, 0, 0],    
                             [0, 0, 0, 0],  
                             [0, 0, 0, 0]]  
# Use nested for loop on matrix A  
for a in range(len(A)):    
   for b in range(len(A[0])):    
          transResult[b][a] = A[a][b] # store transpose result on empty matrix          
# Printing result in the output  
print("The transpose of matrix A is: ")  
for res in transResult:    
   print(res)  
