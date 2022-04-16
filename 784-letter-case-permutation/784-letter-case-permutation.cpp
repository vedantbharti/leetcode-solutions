class Solution {
    
void letterUtil(string s, int n, vector<string> &ans, int start){
    
    ans.push_back(s);
    
    for(int i=start;i<n;i++){
        char temp = s[i];
        if(((int)s[i]>=65 && (int)s[i]<=90) || ((int)s[i]>=97 && (int)s[i]<=122)){
            if(s[i]==tolower(s[i])){
                s[i] = toupper(s[i]);
            } else {
                s[i] = tolower(s[i]);
            }
            
            letterUtil(s,n,ans,i+1);
            s[i] = temp;
        }
    }
    
    return;
}
    
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> ans;
        letterUtil(s,n,ans,0);
        return ans;
    }
};