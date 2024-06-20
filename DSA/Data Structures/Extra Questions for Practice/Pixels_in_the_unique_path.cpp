#include<bits/stdc++.h>
using namespace std;
struct box
{
    int id,up,down,left,right;
    bool reached = false;
};
bool dest = false;
void find(box s[],vector<int> &x,int curr,int m,int n )
{
    s[curr].reached = true;
 
    if(curr == m*n)
    {
        dest = true;
        return ;
    }
   
     if(!dest)
   x.push_back(curr);


      if(s[curr].right && !s[curr+1].reached )
    {  
        find(s,x,curr+1,m,n);
        

        
    }
    if(s[curr].down && !s[curr+n].reached )
    {  
        find(s,x,curr+n,m,n);

    }
    if(s[curr].up && !s[curr-n].reached )
    {   
        find(s,x,curr-n,m,n);

      
    }
   
    if(s[curr].left && !s[curr-1].reached )
    {  
        find(s,x,curr-1,m,n);
    }
  if(!dest)
   x.pop_back();


}
void solve()
{
    int m,n;
    cin>>m>>n;
    box s[(m*n)+1];
    vector<int> ans;
    // ans.push_back(1);
    for(int i = 1;i<=m*n;i++)
    {
        cin>>s[i].id>>s[i].up>>s[i].right>>s[i].down>>s[i].left;
    }
find(s,ans,1,m,n);
    for(int elem:ans)
    {
        cout<<elem<<" ";
        // if(elem == m*n)
        // break;
    }
    cout<<m*n;
    
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
