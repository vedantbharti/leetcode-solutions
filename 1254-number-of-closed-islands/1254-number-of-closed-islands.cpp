class Solution {
    
bool findNumberOfIslands(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited){
    int m = grid.size(), n = grid[0].size();
    
    if(i<0 || i==m || j<0 || j==n){
        return false;
    }
    
    if(grid[i][j]==1 || visited[i][j]==1){
        return true;
    }
    
    //if(visited[i][j]==1) return false;
    
    visited[i][j] = 1;
    
    // if(findNumberOfIslands(i-1,j,grid,visited) && findNumberOfIslands(i+1,j,grid,visited) && findNumberOfIslands(i,j-1,grid,visited) && findNumberOfIslands(i,j+1,grid,visited)) return true; ------>   this is not working, why????
    
    bool up = findNumberOfIslands(i-1,j,grid,visited);
    bool down = findNumberOfIslands(i+1,j,grid,visited);
    bool left = findNumberOfIslands(i,j-1,grid,visited);
    bool right = findNumberOfIslands(i,j+1,grid,visited);
    
    if(up&&down&&left&&right) return true;
    
    return false;
}
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && visited[i][j]==0){
                    if(findNumberOfIslands(i,j,grid,visited)) ans++;
                }
            }
        }
        
        return ans;
    }
};