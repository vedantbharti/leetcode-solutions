class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<char,int> umap;
        
        for(int i=0;i<s.size();i++){
            umap[s[i]]++;
            umap[t[i]]--;
            if(umap[s[i]]==0) umap.erase(s[i]);
            if(umap[t[i]]==0) umap.erase(t[i]);
        }
        if(umap.empty()) return true;
        return false;
    }
};