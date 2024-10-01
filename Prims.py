# Prims algorithm for finding the minimum spanning tree for an undirected graph.
import sys
class Graph:
    def __init__(self,vertices):
        self.vertices = vertices
        self.graph = [[0 for col in range(vertices)]for row in range(vertices)]
        
    def FindMinVertex(self,value,MSTset):
        min = sys.maxsize
        for i in range(self.vertices):
            if(MSTset[i]!=True and value[i] < min):
                min = value[i]
                vertex = i
        return vertex
        
    def printMst(self,parent):
        print("Edge\tValue")
        for i in range(1,self.vertices):
            print(parent[i],"---",i,"\t  ",self.graph[parent[i]][i],sep = "")
        
    def findMST(self):
        parent = [None]*self.vertices
        value = [sys.maxsize]*self.vertices
        MSTset = [False]*self.vertices
        parent[0] = -1 #Start node has no parent
        value[0] = 0  #Start node has value 0 to get picked up  first
 
        for cout in range(self.vertices):
            u = self.FindMinVertex(value,MSTset)
            MSTset[u] = True
            for v in range(self.vertices):
                if(self.graph[u][v]!=0 and MSTset[v]==False and self.graph[u][v]<value[v]):
                    value[v] = self.graph[u][v]
                    parent[v] = u
        self.printMst(parent)

vertices = int(input("Enter the no.of vertices : "))
g = Graph(vertices)
print("Enter the adjacency matrix(if there is no path enter 999): ")
graph = [[0 for col in range(vertices)]for row in range(vertices)]
for i in range(vertices):
    graph[i]=list(map(int,input().split(" ")))
g.graph = graph
g.findMST()
