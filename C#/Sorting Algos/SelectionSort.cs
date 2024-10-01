using System;
class Program
{
    static void Main(string[] args)
    {
        int array_size = 10;
        int[] array = new int[10] { 100, 50, 20, 40, 10, 60, 80, 70, 90, 30 };
        Console.WriteLine("The Array Before Selection Sort is: ");
        for (int i = 0; i &lt; array_size; i++)
        {
            Console.WriteLine(array[i]);
        }
        int tmp, min_key;
 
        for (int j = 0; j < array_size - 1; j++)
        {
            min_key = j;
 
            for (int k = j + 1; k < array_size; k++)
            {
                if (array[k] < array[min_key])
                {
                    min_key = k;
                }
            }
 
            tmp = array[min_key];
            array[min_key] = array[j];
            array[j] = tmp;
        }
 
        Console.WriteLine("The Array After Selection Sort is: ");
        for (int i = 0; i < 10; i++)
        {
            Console.WriteLine(array[i]);
        }
        Console.ReadLine();
    }
}
