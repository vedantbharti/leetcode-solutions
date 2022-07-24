class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forwardProduct(n,1), reverseProduct(n,1);
        for(int i=1;i<n;i++){
            forwardProduct[i] = forwardProduct[i-1]*nums[i-1];
        }
        
        for(int i=n-2;i>=0;i--){
            reverseProduct[i] = reverseProduct[i+1]*nums[i+1];
        }
        
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            ans[i] = forwardProduct[i]*reverseProduct[i];
        }
        
        return ans;
    }
};