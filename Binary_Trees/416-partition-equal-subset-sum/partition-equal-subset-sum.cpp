class Solution {
public:
    
    bool subsetsum(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        if(nums[0] <= target)
            dp[0][nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int t=1;t<=target;t++){
                bool notTake = dp[i-1][t];
                bool Take = false;
                if(nums[i] <= t){
                    Take = dp[i-1][t-nums[i]];
                }
                dp[i][t] = Take || notTake;
            }
        }
        return dp[n-1][target];
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if(totalSum % 2 == 1) return false;
        int target = totalSum/2;
        return subsetsum(nums,target);
    }
};