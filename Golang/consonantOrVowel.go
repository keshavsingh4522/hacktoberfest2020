package main

import (
	"fmt"
)

func vowelOrConsonant(character rune) {
	if character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u' || character == 'A' || character == 'E' || character == 'I' || character == 'O' || character == 'U' {
		fmt.Printf(" %c is vowel\n", character)
	} else {
		fmt.Printf(" %c is consonant\n", character)
	}

}
func main() {
	vowelOrConsonant('E') // vowel
	vowelOrConsonant('t') // consonant
}
