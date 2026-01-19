class Solution {
  public:
    
    vector<int> toposort(int v, vector<vector<int>> &adj){
        vector<int> indegree(v,0);
        
        for(int i=0;i<v;i++){
            for(int node : adj[i]){
                indegree[node]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return topo;
    }
    
    string findOrder(vector<string> &words) {
        int n = words.size();
        int k = 26;
        
        vector<vector<int>> adj(k);
        set<int> present;
        
        // Mark which characters are present
        for(auto &w : words){
            for(char c : w){
                present.insert(c-'a');
            }
        }
        
        // Build the graph by comparing adjacent words
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(), s2.size());
            
            bool found = false;
            for(int ptr=0; ptr<len; ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
                    found = true;
                    break;
                }
            }
            
            // Check for invalid case: s1 is longer and s2 is a prefix of s1
            if(!found && s1.size() > s2.size()){
                return "";  // Invalid dictionary
            }
        }
        
        vector<int> topo = toposort(k, adj);
        
        // Check for cycle: if topo sort doesn't include all present characters
        int count = 0;
        for(int node : topo){
            if(present.count(node)){
                count++;
            }
        }
        
        if(count != present.size()){
            return "";  // Cycle detected
        }
        
        string ans = "";
        for(auto it: topo){
            // Only include characters that are present in the dictionary
            if(present.count(it)){
                ans += char(it + 'a');
            }
        }
        return ans;
    }
};
