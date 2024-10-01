public class testgarbage1 {
    public void finalize(){
        System.out.println("object is garbage collected");
    }
    public static void main(String[] args) {
        testgarbage1 s1=new testgarbage1();
        testgarbage1 s2=new testgarbage1();
        s1=null;
        s2=null;
        System.gc();
    }
}
