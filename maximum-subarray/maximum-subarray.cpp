class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n,0);
        sum[0] = nums[0];
        for(int i=1;i<n;i++){
            sum[i] = sum[i-1] + nums[i];
        }
        
        int dp[n+1];
        dp[0] = INT_MIN;
        int min_sum = 0;
        for(int i=0;i<n;i++){
            dp[i+1] = max(sum[i]-min_sum,dp[i]);
            min_sum = min(sum[i],min_sum);
        }
        
        return dp[n];
    }
};