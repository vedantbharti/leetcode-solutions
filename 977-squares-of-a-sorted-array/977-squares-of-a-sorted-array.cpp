class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int start = 0, end = nums.size()-1;
        int pointer = end;
        while(start<=end){
           if(nums[start]*nums[start]<nums[end]*nums[end]){
               ans[pointer] = nums[end]*nums[end];
               end--;
           } else if(nums[start]*nums[start]>=nums[end]*nums[end]){
               ans[pointer] = nums[start]*nums[start];
               start++;
           }
            
            pointer--;
        }
        
        return ans;
    }
};