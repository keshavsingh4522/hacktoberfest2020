//always work in sorted data structure
//lower bound fuction it returns location of given no aur no greater than to it if the no is not not present if we have multiple element and we use lower bound then it return first
//upper bound function always return the value greater to it 
# include<bits/stdc++.h>
using namespace std;

int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;
cin>>n;
int a[n];
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}
sort(a,a+n);
for (int i = 0; i < n; i++)

{
    cout<<a[i]<<" ";
}
cout<<endl;
int *ptr1=upper_bound(a,a+n,5);
int *ptr2=lower_bound(a,a+n,5);
cout<<*ptr1<<*ptr2;



return 0;
}