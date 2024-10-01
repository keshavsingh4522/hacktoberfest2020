import java.util.*;

public class topologicalSortGraphs {
    ArrayList<ArrayList<Integer>> graph;
    int v;

    topologicalSortGraphs(int v){
        this.v = v;
        graph = new ArrayList<ArrayList<Integer>>();

        for(int i=0;i<v;i++){
            graph.add(new ArrayList<Integer>());
        }
    }

    public static void main(String args[]){
        topologicalSortGraphs g = new topologicalSortGraphs(5);

        // g.addEgde(5, 0);
        // g.addEgde(5, 2);
        // g.addEgde(2, 3);
        // g.addEgde(4, 0);
        // g.addEgde(4, 1);
        // g.addEgde(3, 1);

        g.addEgde(1, 2);
        g.addEgde(1, 3);
        g.addEgde(2, 3);
        g.addEgde(2, 4);
        g.addEgde(4, 3);
        g.addEgde(3, 5);
        g.addEgde(4, 5);

        g.dfs(5);
    }

    void dfs(int s){
        Stack<Integer> sta = new Stack<Integer>();
        boolean vis[] = new boolean[v];
        for(int i=0;i<v;i++)
        if(vis[i] == false)
        dfsUtil(i, vis, sta);

        while(!sta.isEmpty()){
            System.out.print(sta.pop()+" ");
        }
    }

    void dfsUtil(int s, boolean vis[], Stack<Integer> sta){
        vis[s] = true;
        // System.out.println(s+" ");
        Iterator<Integer> i = graph.get(s).iterator();
        while(i.hasNext()){
            int n = i.next();
            if(!vis[n]){
                dfsUtil(n, vis, sta);
            }
        }
        sta.push(s);
    }

    void addEgde(int u,int v){
        graph.get(u).add(v);
    }
}
