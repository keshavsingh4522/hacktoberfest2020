#include <bits/stdc++.h>

#define lli long long int
#define pb push_back
#define mod 1000000007
#define w(x) int x ; cin>>x ; while(x--)
#define sortl(v) sort(v.begin() , v.end());
#define sortg(v,int) sort(v.begin() , v.end() , greater<int>());
#define forl(i,a,b) for (int i=a ; i<b ; ++i)
#define fore(i,a,b) for (int i=a ; i<=b ; ++i)
#define foril(i,a,b,p)   for(i=a ; i<b ; i+=p)
#define forie(i,a,b,p)   for(i=a ; i<=b ; i+=p)
#define en "\n"
#define ct(v,x) count(v.begin() , v.end() , x);
#define lb lower_bound
#define ub upper_bound
#define minint numeric_limits<int>::min()
#define maxint numeric_limits<int>::max()

using namespace std;

void spid()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
}

struct node
{
    int key=0 ;
    node* child[2]={NULL,NULL};
};

void addnumber(node* root , int n)
{
    node* temp=root ;
    fore(i,0,31)
    {
        int cb=(n & (1 <<(31-i))) ? 1 : 0 ;
        if(temp->child[cb]==NULL)
        {
            temp->child[cb]=new node ;
        }
        temp=temp->child[cb];
    }
    temp->key=value ;
}

int xor(node* root , int value)
{
    node* temp=root ;
    fore(i,0,31)
    {
        int cb=(n & (1 <<(31-i))) ? 1 : 0 ;
        if(temp->child[1-cb]==NULL) temp=temp->child[cb];
        else temp=temp->child[1-cb];
    }
    return (value^temp->key);
}

int32_t main()
{
    spid();
    node* root=new trie();
    /*insert numbers get the xor*/
	return 0;
}
