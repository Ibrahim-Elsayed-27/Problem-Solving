class Solution {
public:
    string a, b;
    vector<vector<int>> dp;
    int minimumDeleteSum(string s1, string s2) {
        a = s1;
        b = s2;
        dp.assign(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(0, 0);
    }

    int solve(int i, int j){
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == a.size()) {
            int sum = 0;
            for (int k = j; k < b.size(); k++)
                sum += b[k];
            return dp[i][j] = sum;
        }

        if (j == b.size()) {
            int sum = 0;
            for (int k = i; k < a.size(); k++)
                sum += a[k];
            return dp[i][j] = sum;
        }

        if(a[i] == b[j]){
            return solve(i+1, j+1);
        }
        int delete_first = solve(i+1,j) + a[i];
        int delete_second = solve(i, j+1) + b[j];
        return dp[i][j] = min(delete_first, delete_second);
    }
};