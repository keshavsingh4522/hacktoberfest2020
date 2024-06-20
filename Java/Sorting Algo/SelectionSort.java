import java.util.Arrays;
class SelectionSort{

    static void selectionSort(int a[]){
        int len = a.length;

        for( int i = 0; i < len-1; i++){
            int min = i;
            for( int j = i + 1; j < len; j++){
                if(a[j] < a[min])
                    min = j;
            }
                int temp = a[min];
                a[min] = a[i];
                a[i] = temp;
        }
    }

    public static void main(String[] args){
        int a[] = { 9, 4, 2, 1, 5};
        selectionSort(a);
        System.out.println(Arrays.toString(a));
    }
}