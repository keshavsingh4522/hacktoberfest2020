class circularQueue:
    def __init__(self, size):
        self.size = size
        self.queue = [None for _ in range(size)]
        self.front = self.rear = -1

    def enQueue(self, data):
        if (self.rear + 1) % self.size == self.front:
            print('Queue is full\n')

        elif self.front == -1:
            self.rear = 0
            self.front = 0
            self.queue[self.rear] = data

        else:
            self.rear = (self.rear + 1) % self.size
            self.queue[self.rear] = data

    def deQueue(self):
        if self.front == -1:
            print('Queue is empty\n')

        elif self.front == self.rear:
            temp = self.queue[self.front]
            self.front = -1
            self.rear = -1
            return temp

        else:
            temp = self.queue[self.front]
            self.front = (self.front + 1) % self.size
            return temp

    def display(self):
        if self.front == -1:
            print("Queue is empty\n")
        
        elif self.rear >= self.front:
            print ("Elements in Circular Queue are:",
                                           end = " ")
            for i in range(self.front, self.rear + 1):
                print(self.queue[i], end = ' ')
            print()

        else:
            print ("Elements in Circular Queue are:",
                                           end = " ")
            for i in range(self.front, self.size):
                print(self.queue[i], end = " ")
            for i in range(0, self.rear + 1):
                print(self.queue[i], end = " ")
            print ()

        if (self.rear + 1) % self.size == self.front:
            print("Queue is Full\n")

# Driver's Code
ob = circularQueue(5)
ob.enQueue(14)
ob.enQueue(22)
ob.enQueue(13)
ob.enQueue(-6)
ob.display()
print ("Deleted value = ", ob.deQueue())
print ("Deleted value = ", ob.deQueue())
ob.display()
ob.enQueue(9)
ob.enQueue(20)
ob.enQueue(5)
ob.display()