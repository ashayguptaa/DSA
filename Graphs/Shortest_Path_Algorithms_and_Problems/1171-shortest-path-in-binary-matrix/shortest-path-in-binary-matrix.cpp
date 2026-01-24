class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        q.push({1, {0, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if (row == n - 1 && col == n - 1)
                return dis;
            int delrow[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
            int delcol[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

            for (int i = 0; i < 8; i++) {
                int newr = row + delrow[i];
                int newc = col + delcol[i];
                if (newr >= 0 && newc >= 0 && newr < n && newc < n &&
                    grid[newr][newc] == 0 && vis[newr][newc] == 0) {
                    q.push({dis + 1, {newr, newc}});
                    vis[newr][newc] = 1;
                }
            }
        }
        return -1;
    }
};