"""Good morning! Here's your coding interview problem for today.
This problem was recently asked by Google.
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass?"""



def ifk(list1, k):
    for i in range(0, len(list1)):
        for j in range(0, len(list1)):
            if k == list1[i] + list1[j]:
                return True    
    return False 
    
x=int(input('Enter the list size:'))
l1=[]
i=0

print('Enter list elements:\n')
for i in range(x):
    l1.append(int(input()))
       
k=int(input('Enter the no:'))
print(ifk(l1, k)
    
