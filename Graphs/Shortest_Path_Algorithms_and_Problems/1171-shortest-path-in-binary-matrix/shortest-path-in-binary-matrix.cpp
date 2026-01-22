class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>>vis(n , vector<int>(n,0));
        
        queue<pair<pair<int ,int> ,int>>q;

        q.push({{0,0} ,1});
        vis[0][0] = 1;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int r = temp.first.first;
            int c = temp.first.second;
            int dis = temp.second;

            if(r == n-1 && c == n-1) return  dis;

            int dr[8] = {-1 , -1 ,0 , 1,1,1,0,-1};
            int dc[8] = {0,1,1,1,0,-1,-1,-1};
            for(int i = 0; i<8 ; i++){
                int tr = r + dr[i];
                int tc = c + dc[i];
                if(tr >=0 && tr<n && tc>=0 && tc < n){
                    if(grid[tr][tc] == 0 && vis[tr][tc] == 0){
                        q.push({{tr,tc} , dis + 1});
                        vis[tr][tc] = 1;
                    }

                }
            }


        }
        return -1;

        
    }
};