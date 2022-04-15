class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //vector<vector<int>> visited(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    //visited[i][j] = 1;
                }
            }
        }
        
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        int ans = 0;
        while(!q.empty()){
            int i = 0;
            int s = q.size();
            int flag = 0;
            while(i<s){
                auto p = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int x = dx[i] + p.first;
                    int y = dy[i] + p.second;
                    if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                        q.push({x,y});
                        //visited[x][y] = 1;
                        grid[x][y] = 2;
                        flag = 1;
                    }
                }
                i++;
            }
            if(flag) ans++;
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        
        return ans;
    }
};