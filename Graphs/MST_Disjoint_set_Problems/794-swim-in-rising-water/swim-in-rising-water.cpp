class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            minHeap;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();
            int ele = curr[0], r = curr[1], c = curr[2];
            if (r == n - 1 && c == n - 1)
                return ele;

            for (auto dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nc >= 0 && nr >= 0 && nr < n && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    minHeap.push({max(ele, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};