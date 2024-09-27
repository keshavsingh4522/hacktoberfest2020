def inversionsCount(arr, n):

    tmp_arr = [0]*n
    return mergeSort(arr, tmp_arr, 0, n-1)

def mergeSort(arr, temp_arr, left, right):

    inv_count = 0

    if left < right:

        mid = (left + right)//2

        inv_count += mergeSort(arr, temp_arr, left, mid)

        inv_count += mergeSort(arr, temp_arr, mid+1, right)

        inv_count += merge(arr, temp_arr, left, mid, right)

    return inv_count

def merge(arr, temp_arr, left, mid, right):
    i = left
    j = mid+1
    k = left
    inv_count = 0

    while i <= mid and j <= right:

        if arr[i] <= arr[j]:
            temp_arr[k] = arr[i]
            k += 1
            i += 1
        else:
            # Inversion will occur
            temp_arr[k] = arr[j]
            inv_count += (mid-i + 1)
            k += 1
            j += 1

    while i <= mid:
        temp_arr[k] = arr[i]
        k += 1
        i += 1

    while j <= right:
        temp_arr[k] = arr[j]
        k += 1
        j += 1

    for var in range(left, right + 1):
        arr[var] = temp_arr[var]
    print(arr)
    return inv_count


# Driver's Code
arr = [1, 20, 6, 4, 5, 19]
n = len(arr)
result = inversionsCount(arr, n)
print("Number of inversions are", result)