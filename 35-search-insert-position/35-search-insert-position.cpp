class Solution {
    
int binarySearch(vector<int> &nums, int start, int end, int target){
    int mid = (start+end)/2;
    if(mid==0){
        if(nums[0]>=target) return 0;
    } else if(mid==end){
        if(nums[mid]<target) return end+1;
        else if(nums[mid]==target) return end;
    }
    if(nums[mid]<target && nums[mid+1]>target){
        return mid+1;
    } else if(nums[mid]<target){
        return binarySearch(nums,mid+1,end,target);
    } else if(nums[mid]>target && nums[mid-1]<target){
        return mid;
    } else if(nums[mid]>target){
        return binarySearch(nums,0,mid-1,target);
    } else {
        return mid;
    }
}
    
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1){
            if(target<=nums[0]) return 0;
            else return 1;
        }
        return binarySearch(nums, 0, n-1, target);
    }
};