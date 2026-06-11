class Solution {
public:

    void generateSums(vector<int> &arr, vector<vector<int>> &sum)
    {
        int n = arr.size();
        for(int mask=0;mask<(1<<n);mask++)
        {
            int total = 0;
            int cnt =0;
            for(int i=0;i<n;i++)
            {
                if(mask & (1<<i))
                {
                    cnt++;
                    total+=arr[i];
                }
            }
            sum[cnt].push_back(total);
        }
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>left,right;

        for(int i=0;i<n/2;i++) left.push_back(nums[i]);
        for(int i=n/2;i<n;i++) right.push_back(nums[i]);

        vector<vector<int>>leftSum((n/2)+1);
        vector<vector<int>>rightSum((n/2)+1);

        generateSums(left,leftSum);
        generateSums(right,rightSum);

        for(int i=0;i<rightSum.size();i++) sort(rightSum[i].begin(),rightSum[i].end());
        int total = accumulate(nums.begin(),nums.end(),0);
    
        int ans = INT_MAX;
        for(int k=0;k<=n/2;k++)
        {
            int leftSide = k;
            int rightSide = n/2-k;

            for(auto &curr1 : leftSum[k])
            {
                auto &vec = rightSum[rightSide];
                int need = total/2 - curr1;
                auto it = lower_bound(vec.begin(),vec.end(),need);
                if(it!=vec.end())
                {
                    int selected = curr1 + *it;
                    ans = min(ans,abs(total-2*selected));
                }

                if(it!=vec.begin())
                {
                    it--;
                    int selected = curr1 + *it;
                    ans = min(ans,abs(total-2*selected));
                }
            }
        }

        return ans;
    }
};