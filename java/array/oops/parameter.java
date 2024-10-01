import java.util.*;
public class parameter{
    class Student{
        String name;
        int roll;
        Student(){
            System.out.println("consturctor invoked");
        }
        Student(String name){
            this.name=name;
        }
        Student(int roll){
            this.roll=roll;
        }
    }
    public void main(String[] args) {
        Student s1=new Student();
        Student s2=new Student("piyush");
        Student s3=new Student(99);

    }
}
