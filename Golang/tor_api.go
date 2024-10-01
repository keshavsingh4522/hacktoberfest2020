package main

import (
	"github.com/R4yGM/gonion"
	"net/http"
	"time"
	"fmt"
)

func main(){

	var netClient = &http.Client{
		Timeout: time.Second * 10,
	}

	g := gonion.Client{HttpClient: netClient}
	a := g.Details(gonion.Params{Search : "R4y", Running: true, RecommendedVersion: true})
	fmt.Println(a.Relays[0].Nickname)
}

