# include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &s){
  for(int i=0;i<s.size();i++){
     cout<<s[i]<<" ";
  }
  cout<<endl;
}

int main()
{
 vector<int> vec1;
 int element,size;
 cout<<"enter the size of vector\n";
 cin>>size;
for(int i=0;i<size;i++){
    cout<<"enter element to th vector\n";
    cin>>element;
    vec1.push_back(element);
}
// vec1.pop_back();/*remove the last element*/
display(vec1);
vector<int>::iterator iter =vec1.begin();//insert an elemnt athe begining of vector
vec1.insert(iter,50,566);//iter is a pointer pointing at the begining of the vector 50 copy insert in vector at the begining
display(vec1);
return 0;
}