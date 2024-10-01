using System;

class GFG{

static int M = 3;
static int N = 3;

// Function to reverse
// the given 2D [,]arr
static void reverseArray(int [,]arr)
{

    // Traverse each row of [,]arr
    for (int i = 0; i < M; i++) {

        // Initialise start and end index
        int start = 0;
        int end = N - 1;

        // Till start < end, swap the element
        // at start and end index
        while (start < end) {

            // Swap the element
            int temp = arr[i,start];
            arr[i, start] = arr[i, end];
            arr[i, end] = temp;

            // Increment start and decrement
            // end for next pair of swapping
            start++;
            end--;
        }
    }

    // Print the [,]arr after
    // reversing every row
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            Console.Write(arr[i, j] + " ");
        }
        Console.WriteLine();
    }
}

// Driver Code
public static void Main(String[] args)
{
    int [,]arr = { { 1, 2, 3 },
                     { 4, 5, 6 },
                     { 7, 8, 9 } };

    // Function call
    reverseArray(arr);
}
}
