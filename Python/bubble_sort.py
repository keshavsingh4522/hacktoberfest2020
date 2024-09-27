#defined function
def bubble_sort(input_list):
  #get list length
  count = len(input_list)

  #Loop through an array
  for i in range(count):
    for j in range(0, count - i - 1):
      #Switch if greater value is found
      if input_list[j] > input_list[j + 1]:
        input_list[j], input_list[j + 1] = input_list[j + 1], input_list[j]

#Test simple
example_list = [71, 77, 9, 11, 88]

list1=[]

#take user input for list elements

#number of elements in list
num_of_elements = int(input())

for i in range(num_of_elements):
  list1.append(int(input())
               


#call function
bubble_sort(example_list)
print(example_list)
               
#calling function
bubble_sort(list1)
