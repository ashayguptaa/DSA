class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& s : stones) {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_set<int> nodes;
        for (auto& s : stones) {
            ds.unite(s[0], s[1] + maxRow + 1);
            nodes.insert(s[0]);
            nodes.insert(s[1] + maxRow + 1);
        }
        int components = 0;
        for (int it : nodes) {
            if (ds.parent[it] == it) components++;
        }
        return stones.size() - components;
    }
};