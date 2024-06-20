class Queue:
    def __init__(self, capacity):
        self.capacity = capacity
        self.front = self.size = 0
        self.rear = capacity - 1
        self.Q = [None]*capacity

    def isFull(self):
        return self.size == self.capacity

    def isEmpty(self):
        return self.size == 0

    def EnQueue(self, item):
        if self.isFull():
            print('Full')
            return
        self.rear = (self.rear + 1) % self.capacity
        self.Q[self.rear] = item
        self.size = self.size + 1
        print(f"{item} enqueued to queue")

    def DeQueue(self):
        if self.isEmpty():
            print("Empty")
            return
        print(f"{self.Q[self.front]} dequeued from queue") 
        self.front = (self.front + 1) % self.capacity
        self.size = self.size - 1

    def que_front(self):
        if self.isEmpty():
            print('Empty')
            return
        print(f"Front item is {self.front}")

    def que_rear(self):
        if self.isFull():
            print("Full")
            return
        print(f"Rear item is {self.rear}")

# Driver's Code
Q = Queue(30)
Q.EnQueue(10)
Q.EnQueue(20)
Q.EnQueue(30)
Q.EnQueue(40)
Q.DeQueue()
Q.que_front()
Q.que_rear()