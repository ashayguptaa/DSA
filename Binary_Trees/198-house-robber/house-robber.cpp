class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;

        for(int i=0;i<nums.size();i++){
            int take = nums[i];
            if(i>1) take+= prev2;
            int nottake = 0+ prev;

            int curi = max(take,nottake);

            prev2 = prev;
            prev = curi;

        }
        return prev;
    }
};