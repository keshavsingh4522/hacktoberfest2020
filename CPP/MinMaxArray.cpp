//Find minimum and maximum elements of array using 3 methods
// T(n) time complexity.
#include<iostream>
#include<vector>

    using namespace std;

struct minmax
{
    int min;
    int max;
};

//linear method, TC: O(n)
struct minmax findmm(int arr[], int n)
{
    struct minmax mm;
    if(n==1)
    {
        mm.min = arr[0];
        mm.max = arr[0];
        return mm;
    }

    if (arr[0] > arr[1])
    {
        mm.min = arr[1];
        mm.max = arr[0];
    }
    else
    {
        mm.min = arr[0];
        mm.max = arr[1];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] < mm.min)
            mm.min = arr[i];
        else if (arr[i] > mm.max)
            mm.max = arr[i];
        
    }
    return mm;
}

//Divide n Conquer (Tournament method), TC: O(n)
struct minmax findmm(int arr[], int l, int r)
{
    struct minmax mm, mml, mmr;
    if (l==r)
    {
        mm.min = arr[l];
        mm.max = arr[l];
        return mm;
    }

    else if(r== l+1)
    {
        if (arr[l] > arr[r])
        {
            mm.min = arr[r];
            mm.max = arr[l];
        }
        else
        {
            mm.min = arr[l];
            mm.max = arr[r];
        }
        return mm;
    }
    
    int mid;
    mid = (l+r)/2;
    mml = findmm(arr, l, mid);
    mmr = findmm(arr, mid, r);

    if(mml.min<mmr.min)
        mm.min = mml.min;
    else
        mm.min = mmr.min;

    if(mml.max>mmr.max)
        mm.max = mml.max;
    else
        mm.max = mmr.max;
    
    return mm;
}

//Method - 3: Compare in pairs, TC: O(n), fastest
struct minmax findmm(int n, int arr[])
{
    struct minmax mm;
    int i;
    if (n == 1)
    {
        mm.min = arr[0];
        mm.max = arr[0];
        return mm;
    }

    if(n%2 == 0)
    {
        if (arr[0] > arr[1])
        {
            mm.min = arr[1];
            mm.max = arr[0];
        }
        else
        {
            mm.min = arr[0];
            mm.max = arr[1];
        }
        i = 2;
    }
    else
    {
        mm.min = arr[0];
        mm.max = arr[0];
        i = 1;
    }
    
    while(i<(n-1))
    {
        if(arr[i]>arr[i+1])
        {
            if(arr[i]>mm.max)
                mm.max = arr[i];
            if(arr[i+1]<mm.min)
                mm.min = arr[i+1];
        }
        else
        {
            if (arr[i+1] > mm.max)
                mm.max = arr[i+1];
            if (arr[i] < mm.min)
                mm.min = arr[i];
        }
        i += 2;
    }
    return mm;
}

int main()
{
    int arr[50], n;
    cout<<"\nGive number of elements in array: ";
    cin>>n;
    cout<<"\n Enter the elements: \n";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    //iterative
    struct minmax mm = findmm(arr, n);

    //recursive
    struct minmax mm = findmm(arr, 0, n-1);

    //compare in pairs (fastest method)
    struct minmax mm = findmm(n, arr);

    //output
    cout<<"Max: "<<mm.max<<" \nMin: "<<mm.min<<"\n";
    return 0;
}