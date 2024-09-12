# include<bits/stdc++.h>
using namespace std;

void print(map<int,string> &m){
cout<<m.size()<<"\n";
for(auto &pr:m){
    cout<<pr.first<<" "<<pr.second<<endl;
} 
}

int main()
{
 //oderred map store value in memory
 //map store a pair first a key and other is data
 map<int,string> m;
 m[1]="abc";//time complexity nlogn
 m[2]="cdc";
 m[3]="acd";
 m.insert({4,"afg"});
 auto it = m.find(3);
 m.erase(3);//same time complexity
 print(m);
 if(it==m.end()){
     cout<<"no value";
 }
 else{
      cout<<(*it).first<<" "<<(*it).second<<endl;
 }

//m.erase is function that take itrator and in that type of fuction we never give a non exsisting itrator

return 0;
}