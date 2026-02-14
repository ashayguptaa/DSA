class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int rootI = find(i), rootJ = find(j);
        if (rootI != rootJ) {
            if (size[rootI] < size[rootJ]) swap(rootI, rootJ);
            parent[rootJ] = rootI;
            size[rootI] += size[rootJ];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dr[i], nc = c + dc[i];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            ds.unite(r * n + c, nr * n + nc);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n * n; ++i) ans = max(ans, ds.size[ds.find(i)]);

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> seen;
                    int cur = 1;
                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dr[i], nc = c + dc[i];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int root = ds.find(nr * n + nc);
                            if (seen.find(root) == seen.end()) {
                                cur += ds.size[root];
                                seen.insert(root);
                            }
                        }
                    }
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};