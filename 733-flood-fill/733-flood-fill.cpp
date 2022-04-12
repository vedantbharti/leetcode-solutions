class Solution {
    
void  floodFillImpl(vector<vector<int>> &image, int sr, int sc, int newColor, vector<vector<int>> &visited, int color, int m, int n){
    if(sr<0 || sr>=m || sc<0 || sc>=n || image[sr][sc]!=color || visited[sr][sc]==1) return;
    image[sr][sc]=newColor;
    visited[sr][sc] = 1;
    floodFillImpl(image,sr-1,sc,newColor,visited,color,m,n);
    floodFillImpl(image,sr+1,sc,newColor,visited,color,m,n);
    floodFillImpl(image,sr,sc-1,newColor,visited,color,m,n);
    floodFillImpl(image,sr,sc+1,newColor,visited,color,m,n);
    
    return;
}
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        int color = image[sr][sc];
        vector<vector<int>> visited(m,vector<int>(n,0));
        floodFillImpl(image,sr,sc,newColor,visited,color,m,n);
        return image;
    }
};