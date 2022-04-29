class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> uset;
        for(int i=0;i<9;i++){
            uset.clear();
            for(int j=0;j<9;j++){
                if(uset.find(board[i][j])!=uset.end()){
                    return false;
                }
                if(board[i][j]!='.') uset.insert(board[i][j]);
            }
        }
        
        for(int j=0;j<9;j++){
            uset.clear();
            for(int i=0;i<9;i++){
                if(uset.find(board[i][j])!=uset.end()){
                    return false;
                }
                if(board[i][j]!='.') uset.insert(board[i][j]);
            }
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int a = (j/3) + (i/3)*3;
                int b = (j%3) + (i%3)*3;
                if(a%3==0 && b%3==0) uset.clear();
                if(uset.find(board[a][b])!=uset.end()){
                    return false;
                }
                if(board[a][b]!='.') uset.insert(board[a][b]);
            }
        }
        
        return true;
    }
};