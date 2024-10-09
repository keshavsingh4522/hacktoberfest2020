class Solution
{
    //Function to sort an array using quick sort algorithm.
    static void quickSort( int arr[],int l, int h)
    {
        // code here
          if(l<h) {
            int pivot = partition(arr,l,h);
            quickSort(arr,l,pivot-1);
            quickSort(arr,pivot +1 , h);
    }
    }
    static int partition(int arr[], int l, int h)
    {
        // your code here
        int pivot = arr[l];
        int i = l;
        int j = h;
        while(i<j) {
            while(arr[i]<=pivot && i<j) i++;
            while(arr[j]>pivot) j--;
            if(i<j) {
                swap(arr,i,j);
            }
        }
                swap(arr,j,l);
                return j;
        }
        
      static void swap(int arr[], int i, int j){
          int temp = arr[i];
          arr[i] = arr[j];
          arr[j] = temp;
     }
}
