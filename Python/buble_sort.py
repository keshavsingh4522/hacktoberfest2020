#Bubble Sort Algorithm
    def bubbleSort(data):        lenght = len(data)
        for iIndex in range(lenght):            swapped = False
            for jIndex in range(0, lenght - iIndex - 1):
                if data[jIndex] > data[jIndex + 1]:                    data[jIndex], data[jIndex + 1] = data[jIndex + 1], data[jIndex]                    swapped = True
            if swapped == False:                break
        print(data)
