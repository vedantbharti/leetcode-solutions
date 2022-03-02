class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //sliding window kind of problem with hashing
        int start = 0, end = 0;
        int len = 0;
        unordered_map<char,int> umap;
        while(end<s.size()){
            if(umap.find(s[end])!=umap.end() && umap[s[end]]>=start){
                len = max(end-start,len);
                start = umap[s[end]]+1;
                
            }
            umap[s[end]] = end;
            end++;
        }
        len = max(end-start,len);
        
        return len;
    }
};