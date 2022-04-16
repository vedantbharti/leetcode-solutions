class Solution {
    
void permuteUtil(vector<int> &nums, int n, vector<vector<int>> &ans, int start){
    if(start==n){
        //cout<<1<<endl;
        ans.push_back(nums);
        return;
    }
    
    for(int i=start;i<n;i++){
        swap(nums[i],nums[start]);
        permuteUtil(nums, n, ans, start+1);
        swap(nums[start],nums[i]);
    }
    
    return;
}
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        permuteUtil(nums,n,ans,0);
        return ans;
    }
};