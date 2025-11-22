class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_back_iter = m - 1;
        int nums2_back_iter = n - 1;
        int merged_back_iter = m + n - 1;
        while(nums1_back_iter >= 0 && nums2_back_iter >= 0){
            if(nums1[nums1_back_iter] > nums2[nums2_back_iter]){
                nums1[merged_back_iter] = nums1[nums1_back_iter];
                --nums1_back_iter;

            }else{
                nums1[merged_back_iter] = nums2[nums2_back_iter];
                --nums2_back_iter;             
            }

            --merged_back_iter;
        }


        if(nums2_back_iter >= 0){
            while(nums2_back_iter >= 0){
                nums1[merged_back_iter] = nums2[nums2_back_iter];
                --nums2_back_iter;  
                --merged_back_iter; 
            }
        }

    }
};