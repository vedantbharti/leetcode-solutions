class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maximum = nums[0], minimum = nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0){
                swap(maximum,minimum);
            }
            
            maximum = max(nums[i], nums[i]*maximum);
            minimum = min(nums[i], nums[i]*minimum);
            
            ans = max(ans,maximum);
        }
        
        return ans;
    }
};