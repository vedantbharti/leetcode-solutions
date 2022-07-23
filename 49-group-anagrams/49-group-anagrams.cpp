class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> umap;
        for(int i=0;i<strs.size();i++){
            vector<int> v(26,0);
            for(int j=0;j<strs[i].size();j++){
                v[strs[i][j]-'a']++;
            }
            
            umap[v].push_back(strs[i]);
        }
        
        
        vector<vector<string>> ans;
        for(auto u:umap){
            ans.push_back(u.second);
        }
        
        return ans;
    }
};