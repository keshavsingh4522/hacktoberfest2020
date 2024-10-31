class first:
    def __init__(self,graph,start,goal):
        self.start = start
        self.graph = graph
        self.goal=goal

    def bfs_shortest_path(self):
        explored=[]
        queue = [[self.start]]
        if self.start==self.goal:
            return "That was easy! start=goal"
        while queue:
            path = queue.pop()
            node = path[-1]
            if node not in explored:
                neighbors = self.graph[node]
                for neighbor in neighbors:
                    new_path = list(path)
                    new_path.append(neighbor)
                    queue.append(new_path)
            if neighbor == self.goal:
                return new_path
            explored.append(node)
        return "So  sorry, but a connecting path does not exist"
    
graph = {'A':['Z','S','T'],'B':['U','P','G','F'],'C':['D','R','P'],'D':['M'],'E':['H'],'I':['V','N'],'L':['T','M'],'O':['Z','S'],'P':['R'],'U':['V'],'Z':['O','A'],'S':['O','A','R','F'],'T':['A','L'],'M':['L','D'],'R':['S','P','C'],'F':['S','B']}
f = first(graph,'A','B')
print(f.bfs_shortest_path())
        