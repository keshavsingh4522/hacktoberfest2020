// This program returns response from server
package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", handler)
	http.HandleFunc("/name", showName)

	http.ListenAndServe(":8989", nil)
}

func handler(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello from Go web server")
}
func showName(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "Hello from Go web server akshay")
}
