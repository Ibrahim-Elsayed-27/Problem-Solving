#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> dp;

    int solve(int i, vector<int>& arr, int k) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        int currMax = 0;
        int best = 0;

        for (int len = 1; len <= k && i + len - 1 < n; len++) {
            currMax = max(currMax, arr[i + len - 1]);
            best = max(best, currMax * len + solve(i + len, arr, k));
        }

        return dp[i] = best;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        dp.assign(n, -1);
        return solve(0, arr, k);
    }
};
