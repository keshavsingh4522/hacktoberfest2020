#include<iostream>
#include<stack>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;
bool secondcondition(stack<int> s,deque<int> q);
void show_stack(stack<int> s);
void show_queue(deque<int> q);

int main()
{   deque<int> q;
    stack<int> s;
   
 int n;
    cin>>n;
    
    vector<int> x(n);
    
   
    for(int i = 0;i<n;i++)
   {
        cin>>x[i];}


    for(int i = 0;i<x.size();i++)
    {
        int elem = x[i];
        if( q.empty()&&  s.empty() )
        {
            q.push_back(elem);

        }
        else if( q.back()<=elem  )
     {
            q.push_back(elem);
    }
        else if(s.empty() || s.top()>=elem)
     {
            s.push(elem);
    }
        else
        {
               while(s.empty()== false)
               {
                   if(q.front()>s.top())
                   {
                       q.push_back(s.top());
                       s.pop();
                   }
                   else if(secondcondition(s,q))
                   {
                      q.push_back(s.top());
                      s.pop();
                   }
                   else if(s.top()== q.back())
                   {
                      q.push_back(s.top());
                      s.pop();
                   }
                   else
                   {
                       int oooye = q.front();
                        q.pop_front();
                       q.push_back(oooye);
                      
                   }
               }
             
            
               while(elem> q.front())
               {
                   int oooye = q.front();
                
                   q.push_back(oooye);
                   q.pop_front();
               }
               
                s.push(q.front());
                   q.pop_front();
               s.push(elem);
               
               while(q.back()<=q.front())
               {
                   int oooye = q.front();
                   q.pop_front();
                   q.push_back(oooye);
               }
            
    
    
        }
        if(q.empty() == false)
        {
            show_queue(q);
            cout<<endl;
        }
        if(s.empty() == false)
        {
            show_stack(s);
            cout<<endl;
        }

     }
}
bool secondcondition(stack<int> s,deque<int> q)
{
    vector<int> x;
    while(q.empty() == false)
    {
         x.push_back(q.front());
         q.pop_front();
    }
    return (is_sorted(x.begin(),x.end())) && (s.top()> *max_element(x.begin(),x.end()));
}

void show_stack(stack<int> s)
{
    while(s.empty() == false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}

void show_queue(deque<int> q)
{
    while(q.empty() == false)
    {
        cout<<q.front()<<" ";
        q.pop_front();
    }
}