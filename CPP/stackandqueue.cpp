// stack- LIFO LAST IN FIRST OUT
/* 
OPERATIONS-POP,PUSH,TOP
*/
//QUEUE -FIFO FIRST IN FIRST OUT
/*
OPERATIONS MAJORLY-POP,PUSH,FRONT
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while (!s.empty())//return a bool value
    {
        cout << s.top() << "\n";
        s.pop();
    }

   queue<string> q;
   q.push("abc");
    q.push("bcd");
    q.push("cde");
    q.push("def");   
 while (!q.empty())
    {
        cout << q.front() << "\n";
        q.pop();
    }
    return 0;
}