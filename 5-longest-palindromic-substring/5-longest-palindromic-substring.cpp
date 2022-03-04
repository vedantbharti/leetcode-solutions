class Solution {
    //classic dp problem, asked frequently
    //every single character will be palindrome of itself
    //create a 2D array and set its diagonal to true
    //now check if 2 consecutive characters are palindrome
    //if yes, make dp[i][i+1] = true
    //now taking these two characters as center, if we move left from one end and right from
    //other, and the characters match, the string will also be a palindrome
    //set dp[i][j] to be true if s[i]==s[j] and dp[i+1][j-1] is true;
    //start from length of substring to 3 and increase the length to n
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        int len = INT_MIN;
        int start = 0;
        
        for(int i=0;i<n;i++){
            dp[i][i] = true;
            len = 1;
            start = i;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                len = 2;
                start = i;
            }
            
        }
        
        for(int l=3;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j = i+l-1;
                if(s[i]==s[j] && dp[i+1][j-1]==true){
                    dp[i][j] = true;
                    if(j-i+1>len){
                        len = j-i+1;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start,len);
    }
};