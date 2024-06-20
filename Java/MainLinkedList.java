package linkedList;
import java.util.*;
public class MainLinkedList {

	public static void main(String[] args) {
		
		
		MyLinkedList  myLL = new MyLinkedList();
		
//		myLL.add(101);
//		myLL.add(85);
		
//		myLL.print();
		for(int i = 0; i<10; i++) {
			myLL.add(i);
		}
		
		myLL.print();
		
		
		
		
		
		
		
		
		
		
//		List<Integer> ll = new LinkedList<>();
//        List<Integer> al = new ArrayList<>();
		
//		ll.add(12);
//		ll.add(15);
//		ll.add(89);
		
//		getTimeDifference(al);
//		getTimeDifference(ll);
//		
//		System.out.println(ll.get(0));
//	}

//	static void getTimeDifference(List<Integer> list) {
//		
//		long start = System .currentTimeMillis();
//		
//		for(int i = 0; i<100000; i++) {
//			list.add(0, i);
//		}
//		
//		long end = System.currentTimeMillis();
//	System.out.println(list.getClass().getName() +" --> " + (end - start));
	}
}
