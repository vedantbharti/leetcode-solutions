class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int dp[n];
        dp[0] = nums[0];
        dp[1] = nums[1];
        
        int ans = max(nums[0],nums[1]);
        int max_sum = dp[0];
        for(int i=2;i<n;i++){
            dp[i] = max_sum + nums[i];
            max_sum = max(dp[i-1],max_sum);
            ans = max(dp[i],ans);
        }
        
        return ans;
        
    }
};