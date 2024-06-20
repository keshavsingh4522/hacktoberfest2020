from queue import Queue 
  
# Utility function to print the queue 
def Print(queue):
    while (not queue.empty()):
        print(queue.queue[0], end = ", ") 
        queue.get()
  
# Function to reverse the queue 
def reversequeue(queue):
    Stack = [] 
    while (not queue.empty()): 
        Stack.append(queue.queue[0]) 
        queue.get()
    while (len(Stack) != 0): 
        queue.put(Stack[-1]) 
        Stack.pop()
  
# Driver code 
if __name__ == '__main__':
    queue = Queue()
    queue.put(10) 
    queue.put(20) 
    queue.put(30) 
    queue.put(40) 
    queue.put(50) 
    queue.put(60) 
    queue.put(70) 
    queue.put(80) 
    queue.put(90) 
    queue.put(100) 
  
    reversequeue(queue) 
    Print(queue)