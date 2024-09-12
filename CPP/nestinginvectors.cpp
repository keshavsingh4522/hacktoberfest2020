# include<bits/stdc++.h>
using namespace std;
void display(vector<int> &s ){
  for(int i=0;i<s.size();i++){
     cout<<s[i]<<" ";
  }
  cout<<endl;
}

int main()
{
//  vector<pair<int,int>> v={{1,2},{2,3},{3,4}};
// display(v); nesting a vector of pair


//vector's array

// int N;
// cin>>N;
// vector<int> v[N];

// for (int i = 0; i < N; i++)
// {   int n;
//     cin>>n;
//     for(int j=0;j<n;j++)
//     {
//         int element ;
//         cin>>element;
//         v[i].push_back(element);
//     }
//   for(int i=0;i<N;i++){
//    display(v[i]);
//   }
// }

//vctor's of vector 
int N;
cin>>N;
vector<vector<int> > v;

for (int i = 0; i < N; i++)
{   int n;
    cin>>n;
    vector<int> temp;
    for(int j=0;j<n;j++)
    {
        int element ;
        cin>>element;
        temp.push_back(element);
    }
    v.push_back(temp);
}


  for(int i=0;i<N;i++)
  {
   display(v[i]);
  }

return 0;
}