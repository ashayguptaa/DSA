class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<long> ahead(2,0);
        vector<long> curr(2,0);

        ahead[0] = ahead[1] = 0;

        for(int ind=prices.size()-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                long profit =0;
                if(buy){
                    profit = max(-prices[ind] + ahead[0],0+ahead[1]);
                }
                else{
                    profit = max(prices[ind] + ahead[1],0+ahead[0]);
                }
                curr[buy] = profit; 
            }
            ahead = curr;
        }
        return ahead[1];
    }
};