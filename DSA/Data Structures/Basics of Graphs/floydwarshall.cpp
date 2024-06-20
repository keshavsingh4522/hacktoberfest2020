// Implemented using Adjancency Matrix
// Pls Note that this code can be optimised

#include<iostream>
#define INF 99999
using namespace std;
void floydwarshall(int graph[][4],int total_vetices)
{
    
    
    for(int i = 0;i<total_vetices;i++)
    {
        for(int j = 0;j<total_vetices;j++)
        for(int k = 0;k<total_vetices;k++)
        if(j!= k and i!= j and i!=k and  graph[j][i] + graph[i][k] < graph[j][k])
        graph[j][k] = graph[j][i] + graph[i][k];
    }

    
    for(int i = 0;i<total_vetices;i++)
    {
    for(int j = 0;j<total_vetices;j++)
    cout<<graph[i][j]<<" ";
    cout<<"\n";
    }
}
int main()
{ 
    // Sample was taken from GFG

    /* Let us create the following weighted graph 
            10 
    (0)------->(3) 
        |     /|\ 
    5 |     | 
        |     | 1 
    \|/     | 
    (1)------->(2) 
            3     */
    int graph[4][4] = { {0, 5, INF, 10}, 
                        {INF, 0, 3, INF}, 
                        {INF, INF, 0, 1}, 
                        {INF, INF, INF, 0} 
                    }; 
floydwarshall(graph,4);
}