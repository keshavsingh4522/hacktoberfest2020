def binary_search(arr, myvalue):
    start = 0
    end = len(arr) -1 
    middle = int( (start+end) / 2 )
    value = myvalue
    
    print(start, middle, end)
  
    while not(arr[middle] == value):
            
        if arr[middle] > value:
            
            print("left")
            end = middle - 1
            middle = int((start+end)/2)
            
        elif arr[middle] < value:
            print("right")
            start = middle + 1
            middle = int((start+end)/2)
            
        print(start, middle, end)
        
    if sorted_cars[middle] == value:
        print("found")
