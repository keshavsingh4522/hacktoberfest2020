import java.util.Scanner;

public class SelectionSort {
    void sort(){
        Scanner scanner = new Scanner(System.in);
        int arr[] = new int[20];
        //Step-1 Input
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scanner.nextInt();
        }



        //Step-2 Process
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j=i+1;j<=arr.length-1;j++){
                if(arr[i]>arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }

            }
        }

        //Step-3 Output
        System.out.println("-----Selection Sort-----");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        SelectionSort selectionSort = new SelectionSort();
        selectionSort.sort();

    }
}
