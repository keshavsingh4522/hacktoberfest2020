package main

import "fmt"

func main() {
	data := []int{21, 2, 5, 1, 3, 4}
	fmt.Println("Data int not sort", data)
	BubbleSort(data)
	fmt.Println("Data int sort", data)
}

func BubbleSort(data []int) {
	for i := 0; i < len(data); i++ {
		for j := 1; j < len(data)-i; j++ {
			if data[j] < data[j-1] {
				data[j], data[j-1] = data[j-1], data[j]
			}
		}
	}
}
