class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums, dp, 0);
    }

    bool dfs(vector<int>& nums, vector<int>& dp, int position) {
        if (position >= nums.size() - 1) {
            return true;
        }

        if (dp[position] != -1) {
            return dp[position];
        }

        for (int jump = 1; jump <= nums[position]; jump++) {
            if (dfs(nums, dp, position + jump)) {
                dp[position] = 1;
                return true;
            }
        }

        dp[position] = 0;
        return false;
    }
};
