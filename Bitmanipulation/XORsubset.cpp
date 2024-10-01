/*
Find XOR of all subsets of a set
This can be done using the fact that if there are more than 1 element the XOR of all subsets is always 0 and the number otherwise.
*/

#include <stdio.h>
int findsubsetXOR(int set[], int size)
{
    if (size == 1)
    {
        return set[size - 1];
    }
    else
        return 0;
}
int main()
{
    int set[] = {45, 12};
    int size = sizeof(set) / sizeof(set[0]);
    printf("The XOR of all subsets of set of size %d is %d\n", size,
           findsubsetXOR(set, size));
    int set2[] = {65};
    size = sizeof(set2) / sizeof(set2[0]);
    printf("The XOR of all subsets of set of size %d is %d\n", size,
           findsubsetXOR(set2, size));
}

/*
Output
The XOR of all subsets of set of size 2 is 0
The XOR of all subsets of set of size 1 is 65
*/