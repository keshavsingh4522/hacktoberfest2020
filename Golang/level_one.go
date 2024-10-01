package main

import (
	"fmt"
	"net/http"
	"strconv"
)

func encrypt(data string, shift int) string {
	// fmt.Println(data, shift)
	for i := 0; i < len(data); i++ {
		fmt.Printf("%c", data[i]+byte(shift))
	}
	fmt.Println()
	return data
}

func decrypt(data string, shift int) string {
	// fmt.Println(data, shift)
	for i := 0; i < len(data); i++ {
		fmt.Printf("%c", data[i]-byte(shift))
	}
	fmt.Println()
	return data
}

func encryptHandlers(w http.ResponseWriter, r *http.Request) {
	e := r.FormValue("encrypt")
	s := r.FormValue("shift")
	i, err := strconv.Atoi(s)
	if err != nil {
		fmt.Printf("err")
	}
	encrypt(e, i)

	fmt.Fprintln(w, "encrypted ")

}

func decryptHandlers(w http.ResponseWriter, r *http.Request) {
	e := r.FormValue("decrypt")
	s := r.FormValue("shift")
	i, err := strconv.Atoi(s)
	if err != nil {
		fmt.Printf("err")
	}
	decrypt(e, i)

	fmt.Fprintln(w, "dencrypted ")

}

func main() {
	http.HandleFunc("/encrypt", encryptHandlers)
	http.HandleFunc("/decrypt", decryptHandlers)

	fmt.Println("server running on 3000")
	err := http.ListenAndServe(":3000", nil)

	if err != nil {
		fmt.Println(err)
	}
}

//localhost:3000/decrypt?dencrypt=Ij&shift=1
//localhost:3000/encrypt?encrypt=adbchjdbchbadbchbchbd&shift=10
