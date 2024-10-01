# We will learn how to create a singly linked list
# Firstly, create head and tail and initialize them with null
# Secondly, create a blank node and assign it with a value and refernce to null
# Link the nodes to the head and tail.
# overall space and time complexity is O(1)

class Node:
    def __init__(self,value=None):
        self.value = value
        self.next= None

class SLinkedList:
    def __init__(self):
        self.head = None #O(1)
        self.tail = None # O(1)
    def __iter__(self):
        node= self.head
        while node:
            yield node
            node = node.next
    # Insert in Singly Linked list
    def insertSLL(self,value,location): ## O(n) Time complexity ## IIt take in the value of the node and the reference location
        newNode= Node(value) # we create a new node class which takes in "value" as the parameter
        # We check if the value of head is None or not. If it is none then we assign head and tail to newly created node.
        if self.head is None:
            self.head = newNode
            self.tail= newNode
        else:
            if location==0: # 0 means we insert the node in first/beginning position ( HEAD ).
                newNode.next=self.head # Declare new node as head
                self.head=newNode # insert old head's value into new node
            elif location==1: # 1 means we enter the new node in last position (TAIL).
                newNode.next= None # Give new node reference value as NULL
                self.tail.next=newNode # make tails's new value = new node's value
                self.tail=newNode # declare new node as tail of the linked list
            else: # To enter new node in the middle of the Linked List
                tempNode= self.head # saved head's physical location bcoz we have to iterate from beginning/head
                index=0 #  To keep count of the position we reached
                while index < location-1:
                    tempNode = tempNode.next # keep giving "tempNode" the value of the next node
                    index +=1
                # Main Algorithm
                # Inserting newNode between nextNode and tempNode
                nextNode = tempNode.next # tempNode is current node then nextNode is current nodes's next value
                tempNode.next = newNode # current node's next reference is newNode
                newNode.next = nextNode # newNode's reference is nextNode
    # Traverse through a linked list
    def traverseSLL(self): # O(n) Time complexity
        if self.head is None: # No head , No SLL exist
            print("Singly Linked List does not exist")
        else:
            node = self.head # node has head's physical location bcoz we are traversing
            while node is not None:
                print(node.value)
                node= node.next
    # Search a given element in SLL
    def search(self,num):
        if self.head is None:
            print("No SLL to search")
        else:
            nums = []
            node = self.head
            while node is not None:
                nums.append(node.value)
                node = node.next
            if num in nums:
                index = nums.index(num)
                print(f"The element {num} exist at index {index}")
            else:
                print("Element not present in SLL")
    # Deletion of node
    def deleteSLL(self,location):
        if self.head is None:
            print("The SLL does not exist")
        else:
            if location ==0: # beginning
                # we check if SLL has only 1 node means head and tail referenced to the same node
                if self.head== self.tail:
                    self.head= None
                    self.tail= None
                else:
                    self.head= self.head.next
            elif location==1: # last
                # we check if SLL has only 1 node
                if self.head==self.tail:
                    self.head=None
                    self.tail=None
                else:
                    node= self.head
                    while node is not None: # We traverse from SLL
                        if node.next==self.tail: # node before last node is "node.next== self.tail"
                            break
                        node= node.next # reach to next while traversing
                    node.next = None # we assign That node before last node = tail
                    self.tail=node.next # and tail to nodes's next reference
            else:
                tempNode = self.head
                index=0
                while index<location-1:
                    tempNode=tempNode.next
                    index+=1
                nextNode= tempNode.next
                tempNode.next=nextNode.next
    # delete entire list
    def delAll(self):
        if self.head is None:
            print("Nothing to delete")
        else:
            self.head=None
            self.tail=None

SinglyLinkedList= SLinkedList()
SinglyLinkedList.insertSLL(1,1)
SinglyLinkedList.insertSLL(2,1)
SinglyLinkedList.insertSLL(3,1)
SinglyLinkedList.insertSLL(4,1)
SinglyLinkedList.insertSLL(0,0) # insert 0 in first position
SinglyLinkedList.insertSLL(5,1) # 5 at last
SinglyLinkedList.insertSLL(10,3) # 10 at index 3 ( middle )

print([node.value for node in SinglyLinkedList])
SinglyLinkedList.delAll()
print([node.value for node in SinglyLinkedList])
