class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (const auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> discovery(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> bridges;
        int time = 0;

        function<void(int, int)> dfs = [&](int node, int parent) {
            discovery[node] = low[node] = time++;

            for (int neighbor : graph[node]) {
                if (neighbor == parent) continue;

                if (discovery[neighbor] == -1) {
                    dfs(neighbor, node);

                    low[node] = min(low[node], low[neighbor]);

                    if (low[neighbor] > discovery[node]) {
                        bridges.push_back({node, neighbor});
                    }
                } else {
                    low[node] = min(low[node], discovery[neighbor]);
                }
            }
        };

        for (int i = 0; i < n; ++i) {
            if (discovery[i] == -1) {
                dfs(i, -1);
            }
        }

        return bridges;
    }
};