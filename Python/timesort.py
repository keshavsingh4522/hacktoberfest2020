def insertion_sort(array, left=0, right=None):
    if right is None:
        right = len(array) - 1
    for i in range(left + 1, right + 1):
        key_item = array[i]

        j = i - 1

        while j >= left and array[j] > key_item:
            array[j + 1] = array[j]
            j -= 1

        array[j + 1] = key_item

    return array
