public class LinearSearch{
    public static int linearSearch(int number[] , int key){
        for(int i = 0 ; i<number.length ; i++){
            if(key == number[i]){
                return i;
            }
        }
        return -1;
    }
   public static void main(String[] args) {
        int number[]={10,20,30,40,50,70,60};
        int key = 50;
        int result = linearSearch(number , key );
        if (result == -1){
            System.out.println("the key not found");
        }
        else 
        {
            System.out.println("the index of the element = " + result);
        }
    }
}