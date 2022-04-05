class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0;i<numRows;i++){
            vector<int> ans(i+1,0);
            ans[0] = 1;
            for(int j=1;j<=i;j++){
                ans[j] = ans[j-1]*(i-j+1)/j;
            }
            res.push_back(ans);
        }
        return res;
    }
};