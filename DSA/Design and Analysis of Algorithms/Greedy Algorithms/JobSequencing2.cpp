// With Disjoint Set
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    
    vector<int> parent,rank;
    public:
    DisjointSet(int n)
    {
        this->parent = vector<int>(n+1);
        for(int i = 1;i<=n;i++)
        parent[i] = i;
        this->rank = vector<int> (n+1,0);
    }
    int findParent(int elem)
    {
       if(parent[elem] == elem)
       return elem;
       return parent[elem] = findParent(parent[elem]);
    }
    void Union(int a,int b)
    {
        if(findParent(a) == findParent(b))
        return ;
        else
         {  
             int a1 = findParent(a),b1 = findParent(b);

        if(rank[a1] > rank[b1])
            parent[b1] = parent[a1];
        else if(rank[a1] < rank[b1])
        parent[a1] = b1;
        else
         {
             rank[a1]++;
             parent[b1] = parent[a1]; 
          }
         }
    }


};
struct Job {
    char id;
    int profit,deadline;
};
bool comparator(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}
int main()
{
 
 int n, space_for_jobs = 0;
 cout<<"\n Enter number of Jobs : \n";
 cin>>n;
 vector<Job> data(n);
 cout<<"Specify Job Details\n";
 for(int i = 0;i<n;i++)
 {
     cin>>data[i].id >> data[i].deadline >> data[i].profit;
     space_for_jobs = max(space_for_jobs, data[i].deadline);

 }
 sort(data.begin(),data.end(),comparator);
DisjointSet g(space_for_jobs);
 for(Job elem : data)
 {
   int slot = g.findParent(elem.deadline);
//    cout<<slot<<" ";
   if(slot != 0)
   {
       cout<<elem.id<<" ";
       g.Union(slot-1,slot);
   }

 }


}