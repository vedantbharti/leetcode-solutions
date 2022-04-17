class Solution {
    
void numIslandsUtil(vector<vector<char>>& grid, int m, int n, int i, int j){
    if(i<0 || i==m || j<0 || j==n || grid[i][j]=='0'){
        return;
    }
    
    grid[i][j]='0';
    numIslandsUtil(grid,m,n,i+1,j);
    numIslandsUtil(grid,m,n,i-1,j);
    numIslandsUtil(grid,m,n,i,j+1);
    numIslandsUtil(grid,m,n,i,j-1);
}
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    numIslandsUtil(grid,m,n,i,j);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};