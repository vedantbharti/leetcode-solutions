class Solution {
    
void combineUtil(int start, int n, int k, vector<vector<int>> &ans, vector<int> v){
    if(k==0){
        ans.push_back(v);
        return;
    }
    
    for(int i=start;i<=n;i++){
        v.push_back(i);
        combineUtil(i+1,n,k-1,ans,v);
        v.pop_back();
    }
    
    return;
}
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        combineUtil(1,n,k,ans,v);
        return ans;
    }
};