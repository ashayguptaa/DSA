class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<m;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
        vector<int>minTimeToReach(n+1,INT_MAX);
        minTimeToReach[k]=0;
        minHeap.push({0,k});
        while(!minHeap.empty()){
            auto [currentTime,currentNode]=minHeap.top();
            minHeap.pop();
            for(auto [neighborNode, edgeTime]: adj[currentNode]){
                int newTime=currentTime+edgeTime;
                if(newTime<minTimeToReach[neighborNode]){
                    minTimeToReach[neighborNode]=newTime;
                    minHeap.push({newTime,neighborNode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(minTimeToReach[i]==INT_MAX) return -1;
            ans=max(ans,minTimeToReach[i]);
        }
        return ans;
    }
};