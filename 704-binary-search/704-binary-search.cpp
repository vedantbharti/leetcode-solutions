class Solution {
    
int binarySearch(vector<int> &nums, int start, int end, int target){
    if(start>end) return -1;
    if(nums[(start+end)/2]<target){
        return binarySearch(nums,(start+end)/2+1,end,target);
    } else if(nums[(start+end)/2]>target){
        return binarySearch(nums,0,(start+end)/2-1,target);
    } else {
        return (start+end)/2;
    }
}
    
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return -1;
        return binarySearch(nums, 0, n-1, target);
        
    }
};