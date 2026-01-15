class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> firstIndex;
        int prefix = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += (nums[i] == 1 ? 1 : -1);

            if (prefix == 0) {
                maxLen = max(maxLen, i + 1);
            } else if (firstIndex.count(prefix)) {
                maxLen = max(maxLen, i - firstIndex[prefix]);
            } else {
                firstIndex[prefix] = i;
            }
        }

        return maxLen;
    }
};
