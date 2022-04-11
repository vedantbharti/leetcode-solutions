class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> V(256,0);
        int i=0, j=0;
        while(j<n){
            if(V[(int)s[j]]==1){
                ans = max(j-i,ans);
                while(i<j && s[i]!=s[j]){
                    V[(int)s[i]]--;
                    i++;
                }
                i++;
                
            }
            V[(int)s[j]]=1;
            j++;
        }
        
        return max(j-i,ans);
    }
};