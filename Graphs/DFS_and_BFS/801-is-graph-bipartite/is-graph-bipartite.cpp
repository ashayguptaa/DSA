class Solution {
public:
    
    bool dfs(int node, int col, vector<int>& vis, vector<vector<int>>& graph){
        vis[node] = col;
        
        for(auto it: graph[node]){
            if(vis[it] == -1){
                if(dfs(it,!col,vis,graph) == false) return false;
            }
            else if(vis[it] == col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        int color = 0;

        for(int i=0;i<n;i++){
            if(vis[i]== -1){
                if(dfs(i,color,vis,graph) == false) return false;
            }
        }
        return true;
    }
};