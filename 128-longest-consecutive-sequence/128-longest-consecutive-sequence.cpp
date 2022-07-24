class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uset;
        for(int i=0;i<n;i++){
            uset.insert(nums[i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(uset.find(nums[i]-1)==uset.end()){
                int count = 1;
                int temp = nums[i];
                while(uset.find(temp+1)!=uset.end()){
                    temp++;
                    count++;
                }
                
                ans = max(ans,count);
            }
        }
        
        return ans;
    }
};