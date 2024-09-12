# include<bits/stdc++.h>
using namespace std;

int main()
{
 ios_base::sync_with_stdio(false);
cin.tie(NULL);
 map<pair<string,string>,vector<int>> m;
 int n;
 cin>>n;
 // we are storing first name and last name and corresponding marks
 for(int i=0;i<n;i++){
     string fn,ln;
     int ct;
     cin>>fn>>ln>>ct;
     for(int j=0;j<ct;j++){
         int x;
         cin>>x;
         m[{fn,ln}].push_back(x);
         //here pair  is a key
         //and data is vector

     }
     for(auto &pr:m){
         auto &fullname =pr.first;
         auto &list =pr.second;
         cout<<fullname.first<<" "<<fullname.second<<endl;
         cout<<list.size()<<endl;
         for(auto &element :list){
             cout<<element<<" ";
         }
cout<<endl;
     }
 }

return 0;
}