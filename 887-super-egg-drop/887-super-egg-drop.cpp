class Solution {
    
int superEggDropUtil(int k, int n, vector<vector<int>> &dp){
    if(n==0 || n==1 || k==1){
        return n;
    }
    
    if(dp[k][n]!= -1) return dp[k][n];
    
    int start = 1, end = n;
    int ans = INT_MAX;
    while(start<end){
        int mid = (start+end)/2;
        int val1 = superEggDropUtil(k-1,mid-1,dp);
        int val2 = superEggDropUtil(k,n-mid,dp);
        ans = min(ans,1+max(val1,val2));
        if(val1>val2){
            end = mid;
        } else{
            start = mid+1;
        }
    }
    
    dp[k][n] = ans;
    return ans;
}
    
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return superEggDropUtil(k,n,dp);
    }
};