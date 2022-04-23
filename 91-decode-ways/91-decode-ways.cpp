class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,0);
        if(s[0]=='0') return 0;
        dp[0] = 1;
        if(n==1) return 1;
        if(s[0]=='1'){
            if(s[1]=='0'){
                dp[1] = 1;
            } else {
                dp[1] = 2;
            }
        } else if(s[0]=='2'){
            if(s[1]=='0' || s[1]=='7' || s[1]=='8' || s[1]=='9'){
                dp[1] = 1;
            } else {
                dp[1] = 2;
            }
        } else {
            if(s[1]=='0') return 0;
            else dp[1] = 1;
        }
        
        for(int i=2;i<n;i++){
            if(s[i-1]=='1'){
                if(s[i]=='0'){
                    dp[i] = dp[i-2];
                } else {
                    dp[i] = dp[i-1] + dp[i-2];
                }
            } else if(s[i-1]=='2'){
                if(s[i]=='0'){
                    dp[i] = dp[i-2];
                } else if(s[i]=='7' || s[i]=='8' || s[i]=='9'){
                    dp[i] = dp[i-1];
                } else {
                    dp[i] = dp[i-1] + dp[i-2];
                }
            } else {
                if(s[i]=='0'){
                    return 0;
                }
                dp[i] = dp[i-1];
            }
        }
        
        return dp[n-1];
    }
};