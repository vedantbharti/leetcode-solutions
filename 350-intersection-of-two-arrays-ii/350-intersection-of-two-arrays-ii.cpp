class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        vector<int> ans;
        unordered_map<int,int> umap;
        int i=0, j=0;
        while(i<m){
            umap[nums1[i]]++;
            i++;
        }
        
        while(j<n){
            if(umap[nums2[j]]!=0){
                ans.push_back(nums2[j]);
                umap[nums2[j]]--;
            }
            j++;
        }
        
        return ans;
    }
};