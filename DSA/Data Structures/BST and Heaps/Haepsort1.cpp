#include<iostream>
#include<vector>
using namespace std;
void minheapify(vector<int> &x,int index,int heapsize)
{

 int n = x.size()-1;

   int leftchild = x[2*index],rightchild = x[2*index + 1],largest = index;
if (2*index <= heapsize  and leftchild < x[largest])
largest = 2*index;

if((2*index + 1)<= heapsize  and rightchild < x[largest] )
largest = 2*index + 1;

if (largest != index)
{
    swap(x[index],x[largest]);
    minheapify(x,largest,heapsize);
}

}

void buildminheap (vector<int> &x)
{
int n = (x.size()-1)/2 ;

for(int i = n; i >=1  ; i--)
minheapify(x,i,x.size()-1);


}
void heapsort(vector<int> &x)
{
    buildminheap(x);
    int heapsize = x.size()-1;

    while (heapsize> 1) 
    {
        swap(x[1],x[heapsize--]);
        minheapify(x,1,heapsize);


    }

}

int main()
{

    int n;
    cout<<"Enter size of array ";
    cin>>n;
    vector<int> x(n+1);
    
    cout<<"Enter elements of array: ";

    for(int i = 1;i<=n;i++)
    cin>>x[i];
    
   heapsort(x);

    cout<<"Sorted array is: ";

    for(int i = 1 ;i<=n;i++)
    cout<<x[i]<<" ";

}
