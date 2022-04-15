class Solution {
    
bool isValid(vector<vector<int>> &visited, int i, int j){
    if(i<0 || i>=visited.size() || j<0 || j>=visited[0].size() || visited[i][j]!=0) return false;
    
    return true;
}
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> ans(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            
            for(int i=0;i<4;i++){
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                
                if(isValid(visited,x,y)){
                    ans[x][y] = ans[p.first][p.second]+1;
                    q.push({x,y});
                    visited[x][y] = 1;
                }
            }
        }
        
        return ans;
    }
};