class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if(m>n) return false;
        vector<int> counts1(26,0), counts2(26,0);
        for(int i=0;i<m;i++){
            counts1[s1[i]-'a']++;
            counts2[s2[i]-'a']++;
        }
        
        if(counts1==counts2) return true;
        
        for(int i=m;i<n;i++){
            counts2[s2[i]-'a']++;
            counts2[s2[i-m]-'a']--;
            if(counts1==counts2) return true;
        }
        
        
        
        return false;
    }
};