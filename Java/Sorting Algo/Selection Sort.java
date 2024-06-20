public class selectionSort {
    public static void main(String[] args) {
        int[] arr = { 8, -33, 7, 9, 1, 3 };
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }

    static void sort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int last = arr.length - i - 1;
            int max = getmax(arr, last);
            swap(arr, max, last);
        }
    }

    static void swap(int[] arr, int max, int last) {
        int temp = arr[max];
        arr[max] = arr[last];
        arr[last] = temp;
    }

    static int getmax(int[] arr,int last){
        int max = 0;
        for (int i = 0; i = last; i++) {
            if(arr[max]arr[i]){
                max = i;
            }
        }
        return max;
    }
}