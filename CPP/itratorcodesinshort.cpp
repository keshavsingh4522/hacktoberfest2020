# include<bits/stdc++.h>
using namespace std;

int main()
{
//itrators code are are genrally long

vector<int> v={2,3,4,5};
// printing using range based loop
for(int value:v){
    cout<<value<<" ";
}
cout<<endl;
for(int &value:v){//we pass value by refrence here thats why usinfg refrence operator we can make changesin its orignal value

    value++;
    cout<<value<<" ";
}
//auto keyword it automatically detect the datatype of our variable
auto a=1;
cout<<a<<endl;
for(auto &value:v){
   value++;
    cout<<value<<" ";
}
cout<<endl;
return 0;
}