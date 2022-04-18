class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==1) return cost[0];
        int dp[n][2];
        dp[0][0] = cost[0], dp[0][1] = cost[0], dp[1][0] = cost[1], dp[1][1] = cost[1];
        for(int i=2;i<n;i++){
            dp[i][0] = min(dp[i-1][0],dp[i-1][1])+cost[i];
            dp[i][1] = min(dp[i-2][0],dp[i-2][1])+cost[i];
        }
        
        return min(min(dp[n-1][0],dp[n-1][1]),min(dp[n-2][0],dp[n-2][1]));
    }
};