class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> copy_merge;
        int nums1_iter = 0;
        int nums2_iter = 0;
        while(nums1_iter < m && nums2_iter < n){
            if(nums1[nums1_iter] < nums2[nums2_iter]){
                copy_merge.push_back(nums1[nums1_iter]);
                ++nums1_iter;
            }
            else{
                copy_merge.push_back(nums2[nums2_iter]);
                ++nums2_iter;
            }
        }
        if(nums1_iter < m){
            while(nums1_iter < m){
                copy_merge.push_back(nums1[nums1_iter]);
                ++nums1_iter;
            }
        }
        if(nums2_iter < n){
            while(nums2_iter < n){
                copy_merge.push_back(nums2[nums2_iter]);
                ++nums2_iter;
            }
        }
        
        nums1.swap(copy_merge);
    }
};
