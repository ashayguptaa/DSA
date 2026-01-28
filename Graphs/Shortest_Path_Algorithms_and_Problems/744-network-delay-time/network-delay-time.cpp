class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e9);
        dist[k] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time = it.first;
            int node = it.second;
            if(time>dist[node]) continue;
            
            for(auto it: adj[node]){
                int nbr = it.first;
                int wt = it.second;

                if(time+wt<dist[nbr]){
                    dist[nbr] = time + wt;
                    pq.push({time+wt,nbr});
                }
            }
        }

        int ans = *max_element(dist.begin() + 1,dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};