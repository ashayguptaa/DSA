class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev(n,0);

        for(int j=0;j<n;j++){
            prev[j] = matrix[0][j];
        }

        for(int i=1;i<n;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                int up = prev[j];

                int leftD = INT_MAX;
                if(j>0) leftD = prev[j-1];

                int rightD = INT_MAX;
                if(j<n-1) rightD = prev[j+1];

                curr[j] = matrix[i][j] + min(up,min(leftD,rightD));
            }
            prev = curr;
        }
        return *min_element(prev.begin(),prev.end());
    }
};