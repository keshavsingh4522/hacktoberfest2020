public class stringToUpper {
    public static void stringToUpperLower(String upper , String lower){
        System.out.println(upper);
        System.out.println(lower);
    }
    public static void main (String args[]){
        String randoString = "This Is The String";
        String upper = randoString.toUpperCase();
        String lower = randoString.toLowerCase();
        stringToUpperLower(upper , lower);
        
    }
}
