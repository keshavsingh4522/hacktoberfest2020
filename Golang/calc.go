package main  
  
import "fmt"  
  
func main() {  
 
 var operator string  
 var n1, n2 int
 ans := 0  
 
 fmt.Print("Enter 1st Number, operator, 2nd number on same line\n")  
 fmt.Scanln(&n1,&operator,&n2)
 
 switch operator {  
 case "+":  
  ans = n1 + n2  
  break  
 case "-":  
  ans = n1 - n2
  break
 case "*":  
  ans = n1 * n2
  break
 case "/":  
  ans = n1 / n2
  break
 case "%":  
  ans = n1 % n2
  break
 default:  
  fmt.Println("Invalid Operation")  
  break
 }  
 fmt.Printf("%d %s %d = %d", n1, operator, n2, ans)  
}
