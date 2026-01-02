class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            if(mpp[nums[i]] == 0) mpp[nums[i]]++;
            else return nums[i];
        }
        return -1;
    }
};