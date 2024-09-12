# include<bits/stdc++.h>
using namespace std;

int main()
{
pair<int,string> p;//it use to make pair of any data type
// p=make_pair(2,"abc");
p ={2,"abcd"};//another way of initialization
cout<<p.first<<"  "<<p.second<<"\n";
int a[]={1,2,3};
int b[]={2,3,4};
pair<int,int> p_array[3];
p_array[0]={1,2};
p_array[1]={2,3};
p_array[2]={3,4};//here we use it pair for maintianing relation betwen two datatype
swap(p_array[0],p_array[2]);
for(int i=0;i<3;i++){
    cout<<p_array[i].first<<" "<<p_array[i].second<<"\n";
}
return 0;
}