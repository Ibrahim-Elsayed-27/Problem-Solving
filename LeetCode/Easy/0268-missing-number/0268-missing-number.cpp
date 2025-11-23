class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum_size = 0;
        int i=0;
        for(; i< nums.size(); ++i){
            sum_size += i;
            sum_size -= nums[i];
        }

        return sum_size + i; 
    }
};