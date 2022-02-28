class Solution {
    //teaches the use of hashmap
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> diff;
        for(int i=0;i<nums.size();i++){
            diff[nums[i]] = i;
        }
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(diff.find(target-nums[i])!=diff.end() && diff[target-nums[i]]!=i){
                ans.push_back(i);
                ans.push_back(diff[target-nums[i]]);
                break;
            }
        }
        
        return ans;
        
    }
};