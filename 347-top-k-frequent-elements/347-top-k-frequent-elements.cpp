class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> umap;
        for(int i=0;i<n;i++){
            umap[nums[i]]++;
        }
        
        vector<vector<int>> v(n+1);
        for(auto u:umap){
            v[u.second].push_back(u.first);
        }
        
        vector<int> ans;
        for(int i=n;i>=0;i--){
            if(ans.size()>=k) break;
            if(!v[i].empty()){
                ans.insert(ans.end(),v[i].begin(),v[i].end());
            }
        }
        
        return ans;
        
    }
};