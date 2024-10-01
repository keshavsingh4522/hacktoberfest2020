# Queue is a data structure that works on FIFO method which means "FIRST-IN/FIRST-OUT".
# It is like the real life queue/line we make while visiting shops or waiting in queue for our turn.

# The data in the queue enters from the last and when its to delete the first entered data.

##### Operations that we can perform on Queue-
# 1. Create Stack
# 2. Enqueue()
# 3. Dequeue()
# 4. peek()
# 5. isfull()
# 6. isempty()
# 7. delete()

######## Creation of Queue using List without size limit ##########

class Queue:
    def __init__(self):
        self.items =[] # O(1) -  Time and Space Complexity

    def __str__(self):
        values =[str(x) for x in self.items]
        return ' '.join(values)

    def isEmpty(self):
        if self.items == []:
            return True
        else:
            return False

    def enqueue(self,value):
        self.items.append(value)
        return "The item has been enqueued"

    def dequeue(self):
        if self.isEmpty():
            print("No items in the Queue")
        else:
            self.items.pop(0)

    def peek(self):
        if self.isEmpty():
            print("NO items in the queue")
        else:
            return self.items[0]

    def delete(self):
        self.items = None
        print("The Queue has been deleted Successfully")

########### Only Enqueue and Dequeue takes O(n) time complexity, else O(1)################

###########################  CIRCULAR QUEUE (QUEUE WITH LIMITED SIZE) ############################

class QueueLim:
    def __init__(self, maxsize):
        self.items = maxsize * [None]
        self.maxsize = maxsize
        self.start = -1
        self.top = -1

    def __str__(self):
        values = [str(x) for x in self.items]
        return '  '.join(values)

    def isFull(self):
        if self.top + 1 == self.start:
            return True
        elif self.start == 0 and self.top + 1 == self.maxsize:
            return True
        else:
            return False

    def isEmpty(self):
        if self.top == -1 or self.start == -1:
            return True
        else:
            return False

    def enqueue(self,value):
        if self.isFull():
            print("Queue is full")
        else:
            if self.top + 1 == self.maxsize: # if there is no gap between top and start pointers
                self.top = 0
            else:
                self.top +=1
                if self.start == -1:
                    self.start = 0
            self.items[self.top] =value
            return "The element is enqueued in the beginning"

    def dequeue(self):
        if self.isEmpty():
            print("Queue is Empty")
        else:
            firstElement = self.items[self.start]
            start = self.start
            if self.start == self.top:
                self.start = -1
                self.top = -1
            elif self.start +1 == self.maxsize:
                self.start =0
            else:
                self.start +=1
            self.items[start] = None
            return firstElement

    def peek(self):
        if self.isEmpty():
            print("The queue is Empty")
        else:
            return self.items[self.start]

    def delete(self):
        self.items = self.maxsize * [None]
        self.top = -1
        self.start = -1

#LimQueue = QueueLim(4)
#LimQueue.enqueue(1)
#LimQueue.enqueue(2)
#LimQueue.enqueue(3)
#LimQueue.enqueue(4)
#print(LimQueue)
#LimQueue.delete()
#print(LimQueue)

########### Queue Using Linked List #############

class Node:
    def __init__(self, value= None):
        self.value = value
        self.next = next

    def __str__(self):
        return str(self.value)

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __iter__(self):
        node= self.head
        while node:
            yield node
            node=node.next

class Queue:
    def __init__(self):
        self.linkedlist = LinkedList()

    def __str__(self):
        values = [str(x) for x in self.linkedlist]
        return '  '.join(values)

    def enqueue(self,value):
        newNode = Node(value)
        if self.linkedlist.head is None:
            self.linkedlist.head = newNode
            self.linkedlist.tail = newNode
        else:
            self.linkedlist.tail.next = newNode
            self.linkedlist.tail = newNode

    def isEmpty(self):
        if self.linkedlist.head == None:
            return True
        else:
            return False

    def dequeue(self):
        if self.isEmpty():
            print("No Node in Queue")
        else:
            tempNode = self.linkedlist.head
            if self.linkedlist.head==self.linkedlist.tail:
                self.linkedlist.head=None
                self.linkedlist.tail=None
            else:
                self.linkedlist.head = self.linkedlist.head.next
            return tempNode

    def peek(self):
        if self.isEmpty():
            print("No Node in Queue")
        else:
            return self.linkedlist.head

    def delete(self):
        self.linkedlist.head= None
        self.linkedlist.tail= None

'''
customQueue = Queue()
customQueue.enqueue(1)
customQueue.enqueue(2)
customQueue.enqueue(3)
customQueue.enqueue(4)
print(customQueue)
'''

############# Queue using collections module ############
from collections import deque
customQueue = deque(maxlen= 4)
customQueue.append(1)
customQueue.append(2)
customQueue.append(3)
customQueue.append(4)
'''
print(customQueue)
print(customQueue.popleft())
print(customQueue)
customQueue.clear()
print(customQueue)
'''

import queue as q
custQueue = q.Queue(maxsize=4)
#print(custQueue.empty())
custQueue.put(1)
custQueue.put(2)
custQueue.put(3)
custQueue.put(4)
'''
print(custQueue.full())
print(custQueue.get())
print(custQueue.qsize())
'''