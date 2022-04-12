class Solution {
    
int findMaxArea(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& visited, int i, int j){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || visited[i][j]==1){
        return 0;
    }
    visited[i][j] = 1;
    return findMaxArea(grid,m,n,visited,i+1,j)+findMaxArea(grid,m,n,visited,i-1,j)+findMaxArea(grid,m,n,visited,i,j+1)+findMaxArea(grid,m,n,visited,i,j-1)+1;
    
}
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        int max_area = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && grid[i][j]==1) max_area = max(findMaxArea(grid,m,n,visited,i,j), max_area);
            }
        }
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return max_area;
    }
};