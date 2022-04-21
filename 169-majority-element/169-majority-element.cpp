class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> umap;
        int ans = 0;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
            if(umap[nums[i]]>n/2) ans = nums[i];
        }
        
        return ans;
    }
};