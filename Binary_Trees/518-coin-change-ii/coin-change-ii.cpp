class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        if (n == 0)
            return amount == 0;


        vector<unsigned long long>prev(amount+1,0),curr(amount+1,0);
        for (int t = 0; t <= amount; t++) {
            prev[t] = (t % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++) {
            fill(curr.begin(), curr.end(), 0);
            for (int t = 0; t <= amount; t++) {
                unsigned long long notTake = prev[t];
                unsigned long long take = 0;

                if (coins[ind] <= t)
                    take = curr[t - coins[ind]];

                curr[t] = take + notTake;
            }
            prev = curr;
        }

        return prev[amount];
    }
};