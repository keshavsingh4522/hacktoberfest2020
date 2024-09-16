#We have been given a random integer array/list(arr) of size n. Write a function that rotates the given array/list by D elements(towards the left).

from sys import stdin
def swapElements(arr, start, end) :
    arr[start], arr[end] = arr[end], arr[start] 
    
def reverse(arr, start, end): 
    while(start < end):
        swapElements(arr, start, end)
        start += 1
        end -= 1 

def rotate(arr, n, d):
   
    if n == 0 :
        return
    if d >= n and n != 0 :
        d = d % n
    reverse(arr, 0, n - 1) 
    reverse(arr, 0, n - d - 1) 
    reverse(arr, n - d, n - 1)


#Taking Input Using Fats I/O
def takeInput() :
    n = int(stdin.readline().rstrip())
    if n == 0:
        return list(), 0

    arr = list(map(int, stdin.readline().rstrip().split(" ")))
    return arr, n


#to print the array/list 
def printList(arr, n) : 
    for i in range(n) :
        print(arr[i], end = " ")
    print()


#main
t = int(stdin.readline().rstrip())

while t > 0 :
    
    arr, n = takeInput()
    d = int(stdin.readline().rstrip())
    rotate(arr, n, d)
    printList(arr, n)
    
    t -= 1
