// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {

int binarySearch(int start, int end){
    long long mid = ((long long)start+(long long)end)/2;
    if(mid==0 || mid==end){
        if(isBadVersion(mid)) return mid;
    }
    
    if(isBadVersion(mid) && !isBadVersion(mid-1)){
        return mid;
    } else if(isBadVersion(mid)){
        return binarySearch(start,mid-1);
    } else {
        return binarySearch(mid+1,end);
    }
}

public:
    int firstBadVersion(int n) {
        return binarySearch(0,n);
    }
};