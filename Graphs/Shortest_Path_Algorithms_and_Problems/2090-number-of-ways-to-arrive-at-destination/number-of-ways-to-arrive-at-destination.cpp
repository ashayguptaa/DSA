class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<int> ways(n, 0);
        ways[0] = 1;
        vector<long long> distance(n, LLONG_MAX);
        distance[0] = 0;

        vector<vector<pair<int, int>>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;
        pq.push({0, 0});

        while(!pq.empty()){
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > distance[node]) continue;

            for(auto &it : adj[node]){
                int adjNode = it.first;
                int edW = it.second;
                long long newDist = dist + edW;
                if(newDist < distance[adjNode]){
                    distance[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    pq.push({newDist, adjNode});
                }else if(newDist == distance[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n-1] % MOD;
    }
};