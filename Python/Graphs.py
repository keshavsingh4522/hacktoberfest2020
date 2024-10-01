import numpy as np
class Graph:
    def __init__(self,size):
        self.size = size
        self.adj_matrix = []
        for i in range(size):
            self.adj_matrix.append([0 for i in range(size)])
        print("created graph with %d vertices" % (size))
    
    def add_edge(self,vertex1,vertex2):
        vertex1-=1
        vertex2-=1
        if(vertex1==vertex2):
            print("can't add edge on same vertex")
        else:
            self.adj_matrix[vertex1][vertex2]=1
            print("Added edge from %d to %d" % (vertex1,vertex2))
            
    def display(self):
        print()
        print("Adjancy Matrix of Graph:")
        print("  ",end=" ")
        for i in range(self.size):

           print(i+1,end="  ")
        print()
        i=1
        for row in self.adj_matrix:
            print(i,end=" ")
            i+=1
            print(row)

    def path(self,length):
        print()
        print("Printing Adjancy Matrix for path Length %d: " % (length))
        a=np.array(self.adj_matrix)
        res=a
        if length==1:
            print(res)
            return
        for p in range(length-1):    
            if p:
                # res=self.adj_matrix
                a=res
                res=a.dot(self.adj_matrix)
            else:
                res=a.dot(self.adj_matrix)
        print(res)

    def reachablity(self):
        length=self.size
        a=np.array(self.adj_matrix)
        sume=a
        res=[[]]
        if length==1:
            print(res)
            return
        for p in range(length-1):    
            if p:
                # res=self.adj_matrix
                a=res
                res=a.dot(self.adj_matrix)
                
            else:
                res=a.dot(self.adj_matrix)
            sume=sume+res
            
        print()
        print("Reachability Matrix of Graph is :")
        print(sume)
        flag=0
        for i in range(length):
            for j in range(length):
                if sume[i][j]==0:
                    flag=1
        if flag:
            print("Every vertex of graph is not reachable")
        else:
            print("Every vertex of graph is reachable")
        
    def in_degree(self):
        AT=np.array(self.adj_matrix)
        for i in range(self.size):
            for j in range(i+1,self.size):
                AT[i][j],AT[j][i]=AT[j][i],AT[i][j]
        in_matrix=AT.dot(self.adj_matrix)
        print()
        print("In Degree Matrix:")
        print(in_matrix)
        for i  in range(self.size):
            print("In degree of %d vertex is " % (i+1),in_matrix[i][i])
    
    def out_degree(self):
        AT=np.array(self.adj_matrix)
        for i in range(self.size):
            for j in range(i+1,self.size):
                AT[i][j],AT[j][i]=AT[j][i],AT[i][j]
        A=np.array(self.adj_matrix)
        out_matrix=A.dot(AT)
        print()
        print("Out Degree matrix:")
        print(out_matrix)
        for i  in range(self.size):
            print("Out degree of %d vertex is " % (i+1),out_matrix[i][i])
    
g=Graph(5)              #making graph
g.add_edge(1,5)
g.add_edge(1,2)       
g.add_edge(2,4)       
g.add_edge(3,2)       
g.add_edge(4,3)       
g.add_edge(5,4)       
g.add_edge(4,1)   
g.display()             #displaying graph
for i in range(1,6):    #ajdancency matrix of diiferent path lenghts
    g.path(i)
g.reachablity()         #reachablity matrix
g.in_degree()           #in degree matrix
g.out_degree()          #out degree matrix


