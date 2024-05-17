package main

import (
	"encoding/json"
	"fmt"
)

type Select struct {
	Value string `json:"value"`
	Label string `json:"label"`
}

func prettyJSONLog(i interface{}) {
	s, _ := json.MarshalIndent(i, "", "\t")
	fmt.Println(string(s))
}

func main() {

	test := Select{
		Value: "hacktoberfest-2021",
		Label: "Hacktoberfest 2021",
	}

	prettyJSONLog(test)
}
