/*I have solved this problem using binary search. The time complexity is O(log n)*/
#include <iostream>
using namespace std;
 
int main()
{

    int n = 0;
    cout<<"Enter the number of elements(prices):";
    cin>>n;
    int PriceOfDay[n];

    cout<<"\nEnter the elements(prices):\n";

    for(int i=0;i<n;i++){
        cin>>PriceOfDay[i];
    }

    int max=0;
   

    int low=0;
    int high=n-1;

    while (low<=high){

        if(low==0&&high==0){
            max=PriceOfDay[0];
        }
 
        int mid=(low+high)/2; 

        if ((high==low+1)&&PriceOfDay[low]>PriceOfDay[high])
            max=PriceOfDay[low];

 
        if ((high==low+1)&&PriceOfDay[low]<PriceOfDay[high])
            max=PriceOfDay[mid];
 
     
        if (PriceOfDay[mid]>PriceOfDay[mid+1]&&PriceOfDay[mid]>PriceOfDay[mid-1]){
            max=PriceOfDay[mid];
            break;
        }
 
      
        if (PriceOfDay[mid]>PriceOfDay[mid+1]&&PriceOfDay[mid]<PriceOfDay[mid-1])
            high=mid-1;
 
        else
            low=mid+1;
    }

    cout<<"Maximum price for the Day: Rs "<<max;

    return 0;
}