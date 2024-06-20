// A simple calculator in golang

package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func parseArgs(c []string) (float64, float64, error) {
	num1, err := strconv.ParseFloat(c[0], 64)
	if err != nil {
		return 0.0, 0.0, err
	}
	num2, err := strconv.ParseFloat(c[2], 64)
	if err != nil {
		return 0.0, 0.0, err
	}
	return num1, num2, nil
}

func processStack(e []string) (float64, error) {
	result := 0.0
	for _, v := range e {
		c := strings.Split(v, " ")
		if len(c)-1 < 2 {
			return 0.0, errors.New("error: some arguments are not supplied")
		}
		num1, num2, err := parseArgs(c)
		if err != nil {
			return 0.0, err
		}
		switch c[1] {
		case "*":
			result = num1 * num2
		case "/":
			if num2 == 0.0 {
				return 0.0, errors.New("error: you tried to divide by zero.")
			}
			result = num1 / num2
		case "+":
			result = num1 + num2
		case "-":
			result = num1 - num2
		}
	}
	return result, nil
}

func main() {
	expressions := make([]string, 1)
	for {
		scanner := bufio.NewScanner(os.Stdin)
		fmt.Print("gocalc>")
		for scanner.Scan() {
			expressions = append(expressions, scanner.Text())
			res, err := processStack(expressions)
			if err != nil {
				fmt.Println(err)
			} else {
				fmt.Println(res)
			}
			fmt.Print("gocalc>")
		}
	}
}
