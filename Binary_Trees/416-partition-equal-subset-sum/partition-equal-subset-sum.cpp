class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(begin(nums), end(nums), 0);
        if (totalSum & 1) return false;

        int halfSum = totalSum / 2;
        bitset<10001> dp(1); // dp[0] = true

        for (int num : nums)
            dp |= dp << num;

        return dp[halfSum];
    }
};