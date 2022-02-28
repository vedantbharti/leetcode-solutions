class Solution {
public:
    bool isPalindrome(int x) {
        
        //teaches the use of typecasting
        if(x<0) return false;
        if(x==0) return true;
        long long reverseNum = 0;
        long long temp = x;
        long long prev = 0;
        while(temp!=0){
            reverseNum = prev*10+temp%10;
            prev = reverseNum;
            temp/=10;
        }
        
        return reverseNum==x;
    }
};