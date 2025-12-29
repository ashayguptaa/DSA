class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph and indegree array
        for (auto &p : prerequisites) {
            int course = p[0];
            int pre    = p[1];
            adj[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        // Push all courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int next : adj[node]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        if ((int)order.size() == numCourses) {
            return order;
        }
        return {};
    }
};