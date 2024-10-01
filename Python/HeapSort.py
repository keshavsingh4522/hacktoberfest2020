#Program for heapsort
def heapsort(MyList):
  m = len(MyList)
  for i in range(m//2, -1, -1):
    heapify(MyList, n-1, i)

  for i in range(m-1, -1, -1):
    # swapping last element with the first element
    MyList[i], MyList[0] = MyList[0], MyList[i]
    
    # exclude the last element from the heap
    heapify(MyList, i-1, 0)

def heapify(MyList, n, i):
  max, left, right = i, 2*i + 1, 2*i + 2
  
  # left element is greater than root
  if left <= n and MyList[left] > MyList[max]:
    max = left

  # right element is greater than root
  if right <= n and MyList[right] > MyList[max]:
    max = right

  if max != i:
    MyList[i], MyList[max] = MyList[max], MyList[i]
    heapify(MyList, n, max) 

def PrintList(List1):
  for i in List1:
    print(i, end=" ")
  print("\n")

#sample for running                 
List1 = [5, 0 , 15 , 22 , 7, -4]
n = len(List1)
print("Original List")
PrintList(List1)

heapsort(List1)
print("Sorted List")
PrintList(List1)
