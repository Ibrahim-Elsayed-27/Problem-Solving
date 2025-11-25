class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pairs_sum = 0;
        for(int i=0 ; i< nums.size(); i+=2){
            pairs_sum += nums[i];
        }

        return pairs_sum;
    }
};