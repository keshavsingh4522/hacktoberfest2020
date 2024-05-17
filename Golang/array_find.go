package main


func Find(list []string, item string) (string, bool) {
	for _, i := range list {
		if i == item {
			return i, true
		}
	}
	return "", false
}

func main(){
  list := []string{"a", "b", "c"}

  fmt.Println(Find(list, "a")) // a, true
  fmt.Println(Find(list, "b")) // b, true
  fmt.Println(Find(list, "c")) // c, true
  fmt.Println(Find(list, "d")) // "", false
}
