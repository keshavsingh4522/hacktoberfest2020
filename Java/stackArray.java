public class StackArray {

    public static void main(String[] args) {
        StackArr sa = new StackArr(6);
        sa.push(6);
        sa.push(4);
        sa.push(7);
        sa.push(1);
        sa.display();
        try {
            int k = sa.peek();
            System.out.println("Peek is " + k);
            System.out.println("Pooed an item :" + sa.pop());
            System.out.println("Pooed an item :" + sa.pop());
            System.out.println("Pooed an item :" + sa.pop());
            System.out.println("Pooed an item :" + sa.pop());
            System.out.println("Pooed an item :" + sa.pop());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        StackArray d=new StackArray();
        System.out.println("Binary value of 50 is : ");
        d.decimalToBinary(50);
        
    }
    
    public void decimalToBinary(int no){
        int temp=no, count=0;
        while(temp!=0){
            temp=temp/2;
            count++;
        }
        StackArr mystack= new StackArr(count);
        temp=no;
        while(temp!=0){
            int rem= temp%2;
            temp=temp/2;
            mystack.push(rem);
        }
        while(!mystack.isEmpty()){
            try{
                 System.out.print(mystack.pop());
            }
            catch(Exception e){
                
            }
        }
        System.out.println();
           
    }

}

class StackArr {

    private int maxSize; //size of stack array
    private int[] stackData;
    private int top; //top of stack
//-------------------------------------------------------------------------

    public StackArr(int s) {
        this.stackData = new int[s];
        this.maxSize = s;
        this.top = -1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == maxSize - 1;
    }

    public void push(int item) {
        if (!isFull()) {
            stackData[++top] = item;
        } else {
            System.out.println("Array is full. Cannot push item further more");
        }

    }

    public int pop() throws Exception {
        if (!isEmpty()) {
            int temp = stackData[top];   //return stackData[top--];
            top--;
            return temp;
        } else {
            throw new Exception("Stack is empty cannot pop");
        }
    }

    public int peek() throws Exception {
        if (isEmpty()) {
            throw new Exception("Stack is empty");
        }
        return stackData[top];
    }

    public void display() {
        System.out.println("Start printing stack Data...");
        for (int i = top; i >= 0; i--) {
            System.out.println(stackData[i]);
        }
        System.out.println("End printing stack Data...");
        System.out.println();
    }
}
