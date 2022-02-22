class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int partition_nums1_nums2 = (m+n+1)/2;
        int start = 0, end = m;
        while(start<=end){
            int partition_nums1 = (start+end)/2;
            int partition_nums2 = partition_nums1_nums2-partition_nums1;
            int max_left_nums1 = (partition_nums1==0)?INT_MIN:nums1[partition_nums1-1];
            int min_right_nums1 = (partition_nums1==m)?INT_MAX:nums1[partition_nums1];
            int max_left_nums2 = (partition_nums2==0)?INT_MIN:nums2[partition_nums2-1];
            int min_right_nums2 = (partition_nums2==n)?INT_MAX:nums2[partition_nums2];
            
            if(max_left_nums1<=min_right_nums2 && min_right_nums1>=max_left_nums2){
                if((n+m)%2==0){
                    return (double)                               (max(max_left_nums1,max_left_nums2)+min(min_right_nums1,min_right_nums2))/2.0;
                } else {
                    return (double) max(max_left_nums1,max_left_nums2);
                }
            } else if(max_left_nums1>min_right_nums2){
                end = partition_nums1-1;
            } else {
                start = partition_nums1+1;
            }
        }
        return -1;
    }
};