class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int max1 = nums[0], max2 = max1, minVal = max1;
        
        for(int x : nums) {
            if(x > max1) {
                max2 = max1;
                max1 = x;
            } else if(x > max2) {
                max2 = x;
            }
            
            if(x < minVal) {
                minVal = x;
            }
        }
        
        return max1 + max2 - minVal;
    }
};