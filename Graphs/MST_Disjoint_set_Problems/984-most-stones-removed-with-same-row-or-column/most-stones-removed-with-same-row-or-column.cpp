class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRows = 0;
        int maxCols = 0;
        for(auto it: stones){
            maxRows = max(maxRows,it[0]);
            maxCols = max(maxCols,it[1]);
        }
        DisjointSet ds(maxRows+maxCols+1);
        unordered_map<int,int> stoneNodes;

        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRows+1;
            ds.unionBySize(nodeRow,nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto it: stoneNodes){
            if(ds.findUPar(it.first) == it.first){
                cnt++;
            }
        }

        return stones.size() - cnt;
    }
};