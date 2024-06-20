#include<bits/stdc++.h> 
using namespace std;
bool isValid(int curr,int total,int desiredSum)
{
   return (curr + total) >= desiredSum and curr<=desiredSum;
}
void printSubsets(vector<pair<int,bool>> &data,int curr,int total,int desiredSum,int index=0)
{
    if(!isValid(curr,total,desiredSum))
    return ;

    if(desiredSum == curr)
    {
       
        for(auto elem : data)
        {
            if(elem.second)
            cout<<elem.first<<" ";
        }
        cout<<"\n";
        return ;
    }
    if(index == data.size())
    return ;

    data[index].second = true;
    printSubsets(data,curr + data[index].first,total - data[index].first,desiredSum,index + 1);
    data[index].second = false;
    printSubsets(data, curr,total - data[index].first,desiredSum,index + 1);
}
void solve()
{

int n,desiredSum, sum= 0;
cin>>n;
vector<pair<int,bool>> data(n);
for(int i = 0; i < n; i ++)
{
    cin>>data[i].first;
    sum += data[i].first;
    data[i].second = false;
}
cin>>desiredSum;

printSubsets(data, 0, sum, desiredSum);

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
