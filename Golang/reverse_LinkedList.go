package main
import "fmt"
type Node struct {
   value int
   next *Node
}
func NewNode(value int, next *Node) *Node{
   var n Node
   n.value = value
   n.next = next
   return &n
}
func TraverseLinkedList(head *Node){
   fmt.Printf("Input Linked List is: ")
   temp := head
   for temp != nil {
      fmt.Printf("%d ", temp.value)
      temp = temp.next
   }
   fmt.Println()
}
func ReverseLinkedList(head *Node){
   if head == nil{
      return
   }
   ReverseLinkedList(head.next)
   fmt.Printf("%d ", head.value)
}
func main(){
   head := NewNode(30, NewNode(10, NewNode(40, NewNode(40, nil))))
   TraverseLinkedList(head)
   fmt.Printf("Reversal of the input linked list is: ")
   ReverseLinkedList(head)
}
Output
