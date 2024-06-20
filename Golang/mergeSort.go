package main

func Merge(array []int, low, mid, high int) {
	k := low
	i := low
	j := mid + 1
	x := 0

	var temp [100000]int
	for i <= mid && j <= high {
		if array[i] <= array[j] {
			temp[x] = array[i]
			i++
		} else {
			temp[x] = array[j]
			j++
		}
		x++
		k++
	}
	for i <= mid {
		temp[x] = array[i]
		x++
		i++
		k++
	}
	for j <= high {
		temp[x] = array[j]
		x++
		j++
		k++
	}
	x = 0
	for i = low; i < k; i++ {
		array[i] = temp[x]
		x++
	}
}

func Mergesort(array []int, low, high int) {
	if high <= low {
		return
	}
	mid := (high + low) / 2
	Mergesort(array, low, mid)
	Mergesort(array, mid+1, high)
	Merge(array, low, mid, high)
}
