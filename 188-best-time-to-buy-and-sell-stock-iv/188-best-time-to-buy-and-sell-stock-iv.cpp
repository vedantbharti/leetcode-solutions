class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int dp[k+1][n];
        for(int i=0;i<n;i++){
            dp[0][i] = 0;
        }
        
        for(int i=0;i<=k;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=k;i++){
            int maxDiff = INT_MIN;
            for(int j=1;j<n;j++){
                // for(int k=0;k<j;k++){
                //     dp[i][j] = max(dp[i][j-1],prices[j]-prices[k]+dp[i-1][k]);
                // }
                
                // above commented code can be optimized to
                
                maxDiff = max(dp[i-1][j-1]-prices[j-1],maxDiff);
                dp[i][j] = max(dp[i][j-1],prices[j] + maxDiff);
                
                
                //since, in (prices[j]-prices[k]+dp[i-1][k]), prices[j] is constant
                //and we only need max of dp[i-1][k]-prices[k]....which can be found in each
                //iteration
            }
        }
        
        return dp[k][n-1];
    }
};