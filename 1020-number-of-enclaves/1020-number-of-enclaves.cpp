class Solution {
    
bool countNumEnclaves(int i, int j, vector<vector<int>> &grid, int &sum){
    int m = grid.size(), n = grid[0].size();
    if(i<0 || i==m || j<0 || j==n){
        return false;
    }
    
    if(grid[i][j]==0 || grid[i][j]==2){
        return true;
    }
    
    grid[i][j] = 2;
    
    sum++;
    bool up = countNumEnclaves(i-1,j,grid,sum);
    bool down = countNumEnclaves(i+1,j,grid,sum);
    bool left = countNumEnclaves(i,j-1,grid,sum);
    bool right = countNumEnclaves(i,j+1,grid,sum);
    
    if(up&&down&&left&&right) return true;
    return false;
}
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int sum = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    sum = 0;
                    if(countNumEnclaves(i,j,grid,sum)) ans += sum;
                }
            }
        }
        
        return ans;
    }
};