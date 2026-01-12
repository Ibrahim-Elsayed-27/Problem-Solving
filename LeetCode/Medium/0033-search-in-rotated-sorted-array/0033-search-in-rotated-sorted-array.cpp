class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            return (nums[0] == target? 0: -1);
        }
        
        int pivot = find_pivot(nums);
        int n = nums.size();
        if (target >= nums[pivot] && target <= nums[n - 1]) {
            auto it = lower_bound(nums.begin() + pivot, nums.end(), target);
            if (it != nums.end() && *it == target)
                return it - nums.begin();
        } else {
            auto it = lower_bound(nums.begin(), nums.begin() + pivot, target);
            if (it != nums.begin() + pivot && *it == target)
                return it - nums.begin();
        }
        return -1;
    }

    int find_pivot(vector<int>&nums){   
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        while(l < r){
            mid  = l + (r-l)/2;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l;
    }
};