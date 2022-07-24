class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uset;
        for(int i=0;i<n;i++){
            uset.insert(nums[i]);
        }
        
        int ans = 0;
        int temp = 0;
        for(int i=0;i<n;i++){
            if(uset.find(nums[i]-1)==uset.end()){
                temp = 1;
                int x = nums[i];
                while(uset.find(x+1)!=uset.end()){
                    temp++;
                    x++;
                }
                
                ans = max(ans,temp);
            }
        }
        
        return ans;
    }
};