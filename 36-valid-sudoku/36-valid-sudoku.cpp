class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> uset;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && uset.find(board[i][j])!=uset.end()) return false;
                uset.insert(board[i][j]);
            }
            uset.clear();
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!='.' && uset.find(board[j][i])!=uset.end()) return false;
                uset.insert(board[j][i]);
            }
            uset.clear();
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int a = j/3 + (i/3)*3;
                int b = j%3 + (i%3)*3;
                if(board[a][b]!='.' && uset.find(board[a][b])!=uset.end()) return false;
                uset.insert(board[a][b]);
            }
            uset.clear();
        }
        
        return true;
    }
};