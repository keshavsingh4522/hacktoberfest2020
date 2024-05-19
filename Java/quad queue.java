int SIZE = 5; // Size of Circular Queue
    int front, rear;
    int items[] = new int[SIZE];
  
    Circular_Queue() {
      front = -1;
      rear = -1;
    }
  
    // Check if the queue is full
    boolean isFull() {
      if (front == 0 && rear == SIZE - 1) {
        return true;
      }
      if (front == rear + 1) {
        return true;
      }
      return false;
    }
  
    // Check if the queue is empty
    boolean isEmpty() {
      if (front == -1)
        return true;
      else
        return false;
    }
  
    // Adding an element
    void enQueue(int element) {
      if (isFull()) {
        System.out.println("Queue is full");
      } else {
        if (front == -1)
          front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        System.out.println("Inserted " + element);
      }
    }
  
    // Removing an element
    int deQueue() {
      int element;
      if (isEmpty()) {
        System.out.println("Queue is empty");
        return (-1);
      } else {
        element = items[front];
        if (front == rear) {
          front = -1;
          rear = -1;
        } /* Q has only one element, so we reset the queue after deleting it. */
        else {
          front = (front + 1) % SIZE;
        }
        return (element);
      }
    }
  
