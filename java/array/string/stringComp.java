public class stringComp{
    public static void StringComparing(String first , String second){
        if(first.equals(second)){
            System.out.println("true");
        }
        else
        {
            System.out.println("false");
        }
    }
    public static void main (String args[]){
        String first = "Test the String";
        String second = "test the String";
        StringComparing(first , second);
    }
}