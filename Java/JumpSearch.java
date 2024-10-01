package searching_algos;

public class JumpSearch {

	public static void main(String[] args) {
		int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
	    int x = 55;
	    int index = jump(arr, x);
	    System.out.println("Number " + x +" is at index " + index);
	}
	
	static int jump(int arr[],int x) {
		int step = (int)Math.floor(Math.sqrt(arr.length));
		int prev = 0;
		while(arr[Math.min(step, arr.length)-1] < x) {
			prev=step;
			step+=(int)Math.floor(Math.sqrt(arr.length));
			if(prev >= arr.length)
				return -1;
		}
		while(arr[prev]<x) {
			prev++;
			if(prev == Math.min(step, arr.length))
				return -1;
		}
		if (arr[prev] == x)
            return prev;
        return -1;
	}

}
