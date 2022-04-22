class Solution {
    
int binarySearch(vector<int> &v, int k){
    int n = v.size();
    int start = 0, end = n-1;
    int index = INT_MAX;
    while(start<=end){
        int mid = (start+end)/2;
        if(k<=v[mid]){
            index = min(index,mid);
            end = mid-1;
        } else{
            start = mid+1;
        }
    }
    
    if(index!=INT_MAX) return index;
    return -1;
}
    
public:
    int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         int ans = 0;
//         vector<int> dp(n,1);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                 if(nums[i]>nums[j]){
//                     dp[i] = max(dp[i], dp[j]+1);
//                 }
//             }
            
//             ans = max(dp[i],ans);
//         }
        
//         return ans;
        
        
        // NlogN solution
        
        int n = nums.size();
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i=0;i<n;i++){
            int index = binarySearch(v,nums[i]);
            if(index==-1) v.push_back(nums[i]);
            else v[index] = nums[i];
        }
        
        return v.size();
    }
};