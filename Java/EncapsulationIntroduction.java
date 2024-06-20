package encapsulation;

public class EncapsulationIntroduction {

	public static void main(String[] args) {
		
		Student obj = new Student();
//		obj.name = "Tom";
//		obj.age =   45;
		
		
		
		obj.setAge(15);
		
		System.out.println(obj.getAge());
	}

	
}
