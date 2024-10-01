// Name   : ccdisjoint.c
// Desc   : C Program to find the connected components using the disjoint set.
// Input  : Graph whose connected components are to be determined.
// Output : Display which element belongs to which component.
// Date   : 22/ 06/ 2021
// Author : Sheen Xavier A

#include <stdio.h>

struct disjointSet{
    int rank[1000];
    int parent[1000];
    int n;
}dSet;

void makeSet(int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        dSet.parent[i] = i; // When making the disjoint set we initialize
        dSet.rank[i] = 0;   // the parent of each element as its own and 
    }                       // the rank of each element is set to 0
}

int findSet(int n)
{
    if (dSet.parent[n] == n) // Finds the parent until we reach a root node
        return n;            // In a root node, we have parent[a] = a
    
    dSet.parent[n] = findSet(dSet.parent[n]);
    return dSet.parent[n];
}

int unionSet(int a, int b)
{
    int parentA, parentB, rankA, rankB;
    
    parentA = findSet(a);
    parentB = findSet(b);
    rankA = dSet.rank[parentA];
    rankB = dSet.rank[parentB];
    
    if(parentA == parentB) // If the elements belong to same 
        return -1;            // tree no action is required

    if(rankA > rankB)
    {
        dSet.parent[parentB] = parentA; // If rankA > rankB
        return parentA;                  // Just add the tree to main node
    }                                   // No change in ranks

    if(rankB > rankA)
    {
        dSet.parent[parentA] = parentB; // If rankB >  rankA
        return parentB;                         // Just add the tree to main node
    }                                   // No change in ranks

    dSet.parent[parentB] = parentA;     // If same rank, choose either of 
    dSet.rank[parentA] = 1 + rankA;     // the node and increment its rank by one
    return parentA;
}

int main()
{
    int v, e, i, j, graph[1000][1000], vi, vj;
    printf("Vertices : ");
    scanf("%d", &v);
    makeSet(v);
    printf("Edges : ");
    scanf("%d", &e);

    printf("Enter the edges in the form(vi vj) : \n"); // Reading the Graph
    for(i = 0 ; i < e ; i++)
    {
        scanf("%d %d", &vi, &vj);
        unionSet(vi, vj);
    }

    for(i = 0 ; i < v ; i++)
        printf("Vertex %d belongs to the Component of %d\n", i, findSet(i));
    return 0;
}