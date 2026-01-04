class Solution {
    vector<int> dp;   

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(), -1);
        return canBreak(0, s, wordDict);
    }

    bool canBreak(int i, string& s, vector<string>& wordDict) {
        if (i == s.size()) return true;

        if (dp[i] != -1) return dp[i];

        for (const string& word : wordDict) {
            int len = word.size();

            if (i + len <= s.size() && s.substr(i, len) == word) {
                if (canBreak(i + len, s, wordDict)) {
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }
};
