# include<bits/stdc++.h>
using namespace std;

int main()
{
// use to access value of conatiner which does provide us index like arrays and operator
//.begin() itreator point toward start of container and .end() itrator point toward next to last
vector<int> v ={2,3,4,5,6,7};
for (int i = 0; i < v.size(); i++)
{
    cout<<v[i]<<" ";
}
cout<<"\n";
//declaration of an itretor
vector<int> ::iterator it =v.begin();
// cout<<(*it)<<endl;//it is pointing toward first element
for (it  = v.begin(); it <v.end(); ++it)
{
    cout<<*it<<"  ";
}
vector<pair<int,int>> v_p={{1,2},{2,3},{3,4}};
vector<pair<int,int>> :: iterator it1;
 cout<<"\n";
for (it1 = v_p.begin(); it1!= v_p.end(); it1++)
{
    // cout<<(*it1.first)<<" "<<*it.second<<endl;
    cout<<it1->first<<" "<<it1->second<<endl;//this is another method to print values in ppair using itrarator

}


return 0;
}
