#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    int n,num;
    stack<int> s1,s2;
    vector<int> x;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>num;
        s1.push(num);
        x.push_back(num);
    }
    sort(x.begin(),x.end(),greater<int>());
   while(!s1.empty())
    {
        if(s2.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        
        else if(s2.top()<s1.top())
        {
        int a=s2.top();
            int b=s1.top();
            if((a<10 && b<10)&& abs(a-b)==1)
            {
                s2.pop();
                s1.pop();
                s2.push(10*max(a,b)+min(a,b));
            }
            else if(b>9 && a<10 &&(abs(a-b/10)==1 || abs(a-b%10)==1))
            {
          int   x=b/10;
            int y=b%10;
            s1.pop();
            s2.pop();
                s2.push(10*max(a,x)+min(a,y)); 
            
            }
            else if(a>9 && b>9 && (abs(a/10-b%10)==1 || abs(b/10-a%10)==1))
            {
                s1.pop();
                s2.pop();
                s2.push(10*max(a/10,b/10)+min(a%10,b%10));
            }
            else
        {s2.push(b);
        s1.pop();}}
        
        else if(s2.top()>s1.top())
        {
           int  a=s1.top();
            int b=s2.top();
            if(a<10 && b<10 && abs(a-b)==1)
            {
                s1.pop();
                s2.pop();
                s2.push(10*b+a);
            }
            else if(a<10 && b>9 && a>b/10)
            {
                s2.push(a);
                s1.pop();
            }
            else if(a<10 && b>9 &&(abs(a-b/10)==1 || abs(a-b%10)==1))
            {
               int  x=b/10;
               int  y=b%10;
                s1.pop();
                s2.pop();
                s2.push(10*max(a,x)+min(a,y)); 
                
            }
            else if(a>9 && b>9 && (abs(a/10-b%10)==1 ||abs(b/10-a%10)==1))
            {
                s1.pop();
                s2.pop();
                s2.push(10*max(a/10,b/10)+min(a%10,b%10));
            }
            else
            {
              int   temp=s1.top();
                s1.pop();
                s1.push(s2.top());
                s1.push(temp);
                s2.pop();
                   }
                }            
            }
            
while(!s2.empty())
{
    cout<<s2.top()<<" ";
    s2.pop();
}
cout<<"\n";
for(int i : x)
cout<<i<<" ";

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
