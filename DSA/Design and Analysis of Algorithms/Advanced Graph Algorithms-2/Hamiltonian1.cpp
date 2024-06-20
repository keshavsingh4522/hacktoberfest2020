// This Code uses all possible Permutations to find Hamiltonian Path/Circuit
#include<bits/stdc++.h> 
using namespace std;
void solve()
{
    bool ans = false;
    int n,m,x,y;
    cin>>n>>m;
    vector<set<int>> edges(n);
    vector<int> vertices(n);
    while(m--)
    {
        cin>>x>>y;
        edges[x].insert(y);
        edges[y].insert(x);
        
    }
    for(int i = 0;i<n;i++)
    vertices[i] = i;
    do{
       ans = true;
        for(int i = 0;i<n-1;i++)
        {
          
            if(edges[vertices[i]].find(vertices[i+1]) == edges[vertices[i]].end())
            {
                ans = false;
                break;
            }

        }
        if(ans) break;
    }while(next_permutation(vertices.begin(),vertices.end()));
    ans?cout<<"YES\n":cout<<"NO\n";

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
solve();
return 0;
}
