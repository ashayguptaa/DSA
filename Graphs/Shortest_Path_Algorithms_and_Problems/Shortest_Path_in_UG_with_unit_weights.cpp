class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<int> adj[V];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(V,0);
        for(int i=0;i<V;i++) dist[i] = 1e9;
        
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node]+1<dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};
