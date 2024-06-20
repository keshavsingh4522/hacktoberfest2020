from array import array

# if the output is -1, the key doesn't exist in the array


def binary_search(array, num):
    array.sort()
    high = len(array)-1
    low = 0
    if((len(array) == 0)):
        return -1

    mid = int((low + high)/2)

    while ((high != low) and (array[mid] != num)):
        if(array[mid] < num):
            low = mid+1
        else:
            high = mid
        mid = int((low + high)/2)

    if(array[mid] == num):
        return mid
    else:
        return -1


arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]  # Defines array

x = int(input("Enter a number between 1 and 10: "))  # Gets the user key value

# Displays where the value is found
print("element found at index "+str(binary_search(arr, x)))
