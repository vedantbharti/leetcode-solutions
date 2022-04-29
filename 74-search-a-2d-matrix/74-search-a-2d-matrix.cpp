class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int row_start = 0, row_end = m-1;
        int row_mid;
        while(row_start<=row_end){
            row_mid = (row_start+row_end)/2;
            if(matrix[row_mid][n-1]==target){
                return true;
            } else if(row_mid!=0 && matrix[row_mid-1][n-1]<target && matrix[row_mid][n-1]>target){
                break;
            } else if(row_mid==0 && matrix[row_mid][n-1]>target){
                break;
            } else if(matrix[row_mid][n-1]>target){
                row_end = row_mid-1;
            } else {
                row_start = row_mid+1;
            }
        }
        
        int col_start = 0, col_end = n-1;
        int col_mid;
        while(col_start<=col_end){
            col_mid = (col_start+col_end)/2;
            if(matrix[row_mid][col_mid]==target){
                return true;
            } else if(matrix[row_mid][col_mid]<target){
                col_start = col_mid+1;
            } else {
                col_end = col_mid-1;
            }
        }
        
        return false;
    }
};