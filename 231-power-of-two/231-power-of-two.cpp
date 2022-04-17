class Solution {
public:
    bool isPowerOfTwo(int n) {
        //if n!=0, check the condition, else return if n==0 return n(i.e; false)
        long x = n;
        return x ? (x&(x-1))==0 : false;
    }
};