class Solution {
    
int findMaxArea(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
    int m = grid.size(), n = grid[0].size();
    if(i<0 || i==m || j<0 || j==n || grid[i][j]==0 || visited[i][j]==1){
        return 0;
    }
    
    visited[i][j] = 1;
    return findMaxArea(i-1,j,grid,visited)+findMaxArea(i+1,j,grid,visited)+findMaxArea(i,j-1,grid,visited)+findMaxArea(i,j+1,grid,visited)+1;
}
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    ans = max(ans,findMaxArea(i,j,grid,visited));
                }
            }
        }
        
        return ans;
    }
};