class Solution {
public:
     unordered_map<string, vector<pair<string, double>>> adj; /*define adjacency list */
     /* for path a->b->c result is (a,b) * (b,c) */
     double bfs(string s, string e){
         queue<pair<string,double>> q;      /* BFS queue */
         unordered_set<string> visited;     /* track visited nodes */
         q.push({s,1});                     /* push start node with multiplier 1 */
         visited.insert(s);                 /* make start node visited */
         while(!q.empty()){
             auto f = q.front();
             q.pop();
             for(auto ele : adj[f.first]){
                 if(ele.first.compare(e) == 0){         /* if end node is found return product of current */
                     return f.second * ele.second;      /* running multiplier with value of current edge */
                 }
                 if(visited.find(ele.first) == visited.end()){         /* if the node is not yet visited */
                     visited.insert(ele.first);                        /* make visited */
                     q.push({ele.first, (f.second * ele.second)});     /* push the node and update multiplier*/                    }                 
             }
         }
         return -1;
     }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& qu) {       
        for(int i=0;i<equations.size();i++){            /* for each a/b = x */
            auto eq = equations[i];
            adj[eq[0]].push_back({eq[1], values[i]});   /* put b in adj list of a with value x   */
            adj[eq[1]].push_back({eq[0], 1/values[i]}); /* put a in adj list of b with value 1/x */
        }
        vector<double> res;
        for(auto q : qu){                                  /* for each query (a,b)*/
            if(adj.find(q[0]) != adj.end()){                    /* if a exists in graph */
                if(q[0].compare(q[1]) == 0)                     /* if a == b, store 1*/
                    res.push_back(1);            
                else res.push_back(bfs(q[0], q[1]));            /* else do BFS(a, b) to find path to b */
            }
            else res.push_back(-1);      }
        return res;
    }
};
