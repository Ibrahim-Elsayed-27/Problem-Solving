class Solution {
    vector<int> ones;
public:
    Solution() {
        ones = {0, 1};
    }

    vector<int> countBits(int n) {
        int nearest_power_2 = 1;

        while (ones.size() <= n) {
            int i = ones.size();
            if (nearest_power_2 * 2 <= i)
                nearest_power_2 *= 2;
            ones.push_back(1 + ones[i - nearest_power_2]);
        }

        return vector<int>(ones.begin(), ones.begin() + n + 1);
    }
};
