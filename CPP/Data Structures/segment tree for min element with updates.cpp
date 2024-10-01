#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int tree[4*10001];
int arr[10001];
void build(int pos,int l,int r)
{
    if(l==r)
    {
        tree[pos]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*pos+1,l,mid);
    build(2*pos+2,mid+1,r);
    tree[pos]=min(tree[2*pos+1],tre[2*pos+2]);
}
void update(int pos,int idx,int l,int r,int val)
{
if(l==r)
{arr[idx]=val;
tree[pos]=val;
return;
}
int mid=(l+r)/2;
if(start<=idx&&mid>=idx)
update(2*pos+1,idx,l,mid,val);
else
update(2*pos+2,idx,mid+1,r,val);
tree[pos]=min(tree[2*pos+1],tree[2*pos+2]);
}

int query(int start,int end,int l,int r,int index)
{int k=INT_MAX;
    if(start>r||l>end)
    return k;
    
    if(l<=start&&r>=end)
    return tree[index];
    int mid=(start+end)/2;
    return min(query(start,mid,l,r,2*index+1),query(mid+1,end,l,r,2*index+2);
    
    
}
int main() {
	// your code goes herein

	   int n;
	   cin>>n;
	   for(int i=0;i<n;i++)
	   cin>>arr[i];
	   build(0,0,n-1);
	   int m;
	   cin>>m;
	   for(int i=0;i<m;i++)
	   {
	       int l,r;
	       cin>>l>>r;
	   cout<<query(0,n-1,l-1,r-1,0)<<"\n";
	   
	   }
	 
	
	return 0;
}
