class Main
{
    // Naive recursive function to check if triplet exists in an array
    // with the given sum
    public static boolean isTripletExist(int[] A, int n, int target, int count)
    {
        // if triplet has the desired sum, return true
        if (count == 3 && target == 0) {
            return true;
        }
 
        // return false if the sum is not possible with the current configuration
        if (count == 3 || n == 0 || target < 0) {
            return false;
        }
 
        // recur with including and excluding the current element
        return isTripletExist(A, n - 1, target - A[n - 1], count + 1) ||
                        isTripletExist(A, n - 1, target, count);
    }
 
    public static void main(String[] args)
    {
        int[] A = { 2, 7, 4, 0, 9, 5, 1, 3 };
        int target = 6;
 
        if (isTripletExist(A, A.length, target, 0)) {
            System.out.print("Triplet exists");
        }
        else {
            System.out.print("Triplet doesn't exist");
        }
    }
}
