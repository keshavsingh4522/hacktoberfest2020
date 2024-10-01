package DataStructures.Queues;

class PriorityQueue {
  /** The max size of the queue */
  private int maxSize;
  /** The array for the queue */
  private int[] queueArray;
  /** How many items are in the queue */
  private int nItems;

  public PriorityQueue(int size) {
    maxSize = size;
    queueArray = new int[size];
    nItems = 0;
  }

  public void insert(int value) {
    if (isFull()) {
      throw new RuntimeException("Queue is full");
    } else {
      int j = nItems - 1; // index of last element
      while (j >= 0 && queueArray[j] > value) {
        queueArray[j + 1] = queueArray[j]; // Shifts every element up to make room for insertion
        j--;
      }
      queueArray[j + 1] = value; // Once the correct position is found the value is inserted
      nItems++;
    }
  }

  public int remove() {
    return queueArray[--nItems];
  }

  public int peek() {
    return queueArray[nItems - 1];
  }

  public boolean isEmpty() {
    return (nItems == 0);
  }

  public boolean isFull() {
    return (nItems == maxSize);
  }

  public int getSize() {
    return nItems;
  }
}

public class PriorityQueues {

  public static void main(String[] args) {
    PriorityQueue myQueue = new PriorityQueue(4);
    myQueue.insert(10);
    myQueue.insert(2);
    myQueue.insert(5);
    myQueue.insert(3);
    // [2, 3, 5, 10] Here higher numbers have higher priority, so they are on the top

    for (int i = 3; i >= 0; i--)
      System.out.print(
          myQueue.remove() + " "); // will print the queue in reverse order [10, 5, 3, 2]
  }
}
/* Author @piyush168713 - Piyush Kumar 
https://github.com/piyush168713  */
