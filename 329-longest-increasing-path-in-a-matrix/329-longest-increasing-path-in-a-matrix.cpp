class Solution {
    
int longestIncreasingPathUtil(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<vector<int>> &dp, int i, int j){
    int m = matrix.size(), n = matrix[0].size();
    if(i<0 || i==m || j<0 || j==n){
        return 0;
    }
    
    if(visited[i][j]==true) return dp[i][j];
    
    visited[i][j] = true;
    int left = 0, right = 0, top = 0, bottom = 0;
    if(i+1<m && matrix[i+1][j]>matrix[i][j]) bottom = longestIncreasingPathUtil(matrix,visited,dp,i+1,j);
    if(i-1>=0 && matrix[i-1][j]>matrix[i][j]) top = longestIncreasingPathUtil(matrix,visited,dp,i-1,j);
    if(j+1<n && matrix[i][j+1]>matrix[i][j]) right = longestIncreasingPathUtil(matrix,visited,dp,i,j+1);
    if(j-1>=0 && matrix[i][j-1]>matrix[i][j]) left = longestIncreasingPathUtil(matrix,visited,dp,i,j-1);
    
    return dp[i][j] = max({left,right,top,bottom})+1;
    
    
}
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = -1;
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==false){
                    longestIncreasingPathUtil(matrix,visited,dp,i,j);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        
        return ans;
    }
};