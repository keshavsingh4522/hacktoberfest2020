//Hashing-initilize a arrow to zero and increase count of its given index
 //prefix sum

 //Question we have to find the sum in range l and r in a array
# include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int prefix[N];

int main()
{  
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
       cin>>a[i];
       prefix[i]=prefix[i-1]+ a[i];//storing sum in our preffix array
    }
    //take i=1 in index  
    int q;
    cin>>q;
    while (q--)
    {   int l,r;
        cin>>l>>r;
        long long sum=0;
        // for (int i = l; i <= r; i++)
        // {
        //     sum+=a[i];
        // }
        sum=prefix[r]-prefix[l-1];
        cout<<sum<<endl;
        
    }//o(n) +o(n*q)=max n^2 so we have to optimise our code to o(n)
    //we store sum upto index in a array that is called prefix array
    
 

return 0;
}