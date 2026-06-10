class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0), cur(n,0);
        for(int j=0;j<n;j++) front[j] = triangle[n-1][j];
        
        for (int i = n-2; i >= 0; i--) {
            for (int k = i; k >= 0; k--) {
                cur[k] = triangle[i][k] + min(front[k], front[k+1]);
            }
            front = cur;
        }
        return front[0];
    }
};