//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find
int max1(int a,int b)
{
    if(a>=b)
    return a;
    else 
    return b;
}
int bin(vector<int> a, int beg, int end)
{
    if(beg<=end)
    {
        int mid=(beg+end)/2;
        if(mid-1>=0 && mid+1<=end)
        {
        if(!(a[mid-1]<a[mid] && a[mid]<a[mid+1]))
        return mid;
        else if(a[end]>a[mid])
        return bin(a,beg,mid-1);
        return bin(a, mid+1,end);
        //return max1(bin(a,beg,mid-1),bin(a,mid+1,end));
        }
    }
    return -1;
}
int binary_search(vector<int> a, int beg, int end, int elem)
{
    if(beg<=end)
    {
        int mid=(beg+end)/2;
        if(a[mid]==elem)
        return mid;
        else if(a[mid]<elem)
        return binary_search(a,mid+1,end,elem);
        else
        return binary_search(a,beg,mid-1,elem);
    }
    return -1;
}
int Search(vector<int> vec, int K) {
    //code here
    int n=vec.size();
    
    if(vec[0]<=vec[n-1])
    return binary_search(vec,0,n-1,K);
    else
    {
    int pos=bin(vec,0,n-1);
    int ans=-1;
    ans=binary_search(vec,0,pos,K);
    if(ans==-1)
    ans=binary_search(vec,pos+1,n-1,K);
    
    return ans;
    }
}