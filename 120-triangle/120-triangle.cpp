class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        vector<int> v;
        v.push_back(triangle[0][0]);
        dp.push_back(v);
        for(int i=1;i<triangle.size();i++){
            v.clear();
            for(int j=0;j<triangle[i].size();j++){
                if(j>0 && j<triangle[i].size()-1){
                    v.push_back(min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j]);
                } else if(j==0){
                    v.push_back(dp[i-1][j] + triangle[i][j]);
                } else {
                    v.push_back(dp[i-1][j-1] + triangle[i][j]);
                }
            }
            
            dp.push_back(v);
        }
        
        int ans = INT_MAX;
        for(int i=0;i<dp[dp.size()-1].size();i++){
            ans = min(ans,dp[dp.size()-1][i]);
        }
        
        return ans;
    }
};