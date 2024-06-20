// TSP Using Dynamic Programming
#include<bits/stdc++.h> 
using namespace std;
int giveAns(int startVertex,set<int> remVertex,vector<vector<int>> &edges,map<pair<int,set<int>>,int> &calculatedCost)
{
 

if(calculatedCost.find({startVertex,remVertex}) != calculatedCost.end())
return calculatedCost[{startVertex,remVertex}];

vector<int> costs;
for(int i = 0 ; i < edges.size() ; i ++ )
{
    if(remVertex.find(i) != remVertex.end())
    {
        remVertex.erase(i);
      int cost = edges[startVertex][i] + giveAns(i, remVertex,edges, calculatedCost);
      remVertex.insert(i);
      costs.push_back(cost);
    }

}
calculatedCost[{startVertex,remVertex}] = *min_element(costs.begin(),costs.end());
return calculatedCost[{startVertex,remVertex}];




}
void solve()
{

// Adjacency Matrix Representation of The Graph(Taken from GFG)
// Assuming a (Complete Graph)
vector<vector<int>> data = {
    { 0, 10, 15, 20 },
    { 10, 0, 35, 25 },
    { 15, 35, 0, 30 },
    { 20, 25, 30, 0 }

};
int vert = data.size();
int startingVertex = 0 ;
map<pair<int,set<int>>,int> calculatedCost;
set<int> temp;

for(int i = 0 ; i < vert;i++)
if(i != startingVertex)
calculatedCost[{i,temp}] = data[startingVertex][i]; 


for(int i = 0 ; i < vert; i ++)
if( i != startingVertex)
temp.insert(i);
cout<<giveAns(startingVertex, temp,data, calculatedCost)<<"\n";




}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
