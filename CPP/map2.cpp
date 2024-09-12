# include<bits/stdc++.h>
using namespace std;

int main()
{
 /*inbuilt implementation
 time complexity
 valid key datatype
 */
unordered_map<int,string> m;
m[1] ="abc";
m[2]="cdc";
m[3]="acd";
m[6]="a";
m[5]="cde";
auto it=m.find(7);
if(it !=m.end()){
    m.erase(it);
}




return 0;
}