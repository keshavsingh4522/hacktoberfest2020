//Insertion sort

#include<bits/stdc++.h>

int main()
{
    int s,i,j,current;
    std::cout<<"enter size of array :";
    std::cin>>s;
    int arr[s];
    for(i=0;i<s;i++)
    {
        std::cin>>arr[i];
    }
    
    for(i=1;i<s;i++)
    {
        current=arr[i];
        j=i-1;
        
        while(arr[j]>current&&j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        j++;
        arr[j]=current;
    }
    for(i=0;i<s;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    return 0;
}
