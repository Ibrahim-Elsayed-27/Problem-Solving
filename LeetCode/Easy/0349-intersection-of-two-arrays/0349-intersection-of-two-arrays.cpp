class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> freq_arr1 (1001, 0);
        vector<int> freq_arr2 (1001, 0);
        for(int num: nums1){
            freq_arr1[num]++; 
        }
        for(int num: nums2){
            freq_arr2[num]++; 
        }
        int i = 0;
        vector<int> result;
        while(i < 1001){
            if(freq_arr1[i] >0 && freq_arr2[i] >0){
                result.push_back(i);
            }
            ++i;
        }

        return result;
    }
};