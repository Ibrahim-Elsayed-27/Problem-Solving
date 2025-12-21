class Solution {
    unordered_map<int, bool> dp;
public:
    bool divisorGame(int n) {
        if(n==1) return false;
        if(dp.count(n)) return dp[n];

        for (int x = n-1; x >0; --x) {
            if (n % x == 0) {
                if (!divisorGame(n - x)) {
                    return dp[n] = true;
                }
            }
        }
        return dp[n] = false;
    }
};