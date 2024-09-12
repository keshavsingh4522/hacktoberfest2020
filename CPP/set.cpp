#include <bits/stdc++.h>
using namespace std;
void print(set<string> &s)
{
    for (string value : s)
    {
        cout << value << endl;
    }
}

int main()
{
    //it store only keys like map
    set<string> s;
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    auto it = s.find("abc");
    //s.erase also take itrator
    print(s);
    
   
}