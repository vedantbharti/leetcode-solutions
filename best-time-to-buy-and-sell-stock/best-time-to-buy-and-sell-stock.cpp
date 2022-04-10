class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n];
        dp[0] = 0;
        int min_sell_price = prices[0];
        for(int i=1;i<n;i++){
            int profit = prices[i]-min_sell_price;
            dp[i] = max(dp[i-1],profit);
            min_sell_price = min(min_sell_price,prices[i]);
        }
        
        return dp[n-1];
    }
};