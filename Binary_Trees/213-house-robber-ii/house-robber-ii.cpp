class Solution {
public:
    
    int rob1(vector<long long>& nums) {
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<nums.size();i++){
            int take = nums[i]; if(i>1) take+= prev2;
            int nottake = 0 + prev;
            int curi = max(take,nottake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        long long n = nums.size();
        if (n==1) return nums[0];
        vector<long long> temp1,temp2;

        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!= n-1) temp2.push_back(nums[i]);
        }

        return max(rob1(temp1),rob1(temp2));
    }
};