package main

import "fmt"

func fibonacci(n int) int {
	if n == 0 || n == 1 {
		return n
	} else {
		return (fibonacci(n-1) + fibonacci(n-2))
	}
}
func main() {
	var n, i, j int
	j = 0
	fmt.Print("Enter a number: ")
	fmt.Scanln(&n)
	fmt.Print("Fibonacci series: ")
	for i = 1; i <= n; i++ {
		fmt.Print(fibonacci(j), ", ")
		j++
	}
	fmt.Println()
}
