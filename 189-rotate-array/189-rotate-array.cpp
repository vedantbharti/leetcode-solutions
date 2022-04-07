class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> ans(n,0);
        int start = 0, end = n-1;
        int i=0;
        int j = k-1;
        while(i<k){
            ans[j] = nums[end];
            end--;
            j--;
            i++;
        }
        
        j = k%n;
        while(start<=end){
            ans[j] = nums[start];
            start++;
            j++;
        }
        
        nums = ans;
    }
};