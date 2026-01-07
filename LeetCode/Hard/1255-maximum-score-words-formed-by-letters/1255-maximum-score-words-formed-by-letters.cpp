class Solution {
    int maxScore = 0;

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {

        vector<int> avail(26, 0);
        for (char c : letters) {
            avail[c - 'a']++;
        }

        int n = words.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        vector<int> wordScore(n, 0);

        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                freq[i][c - 'a']++;
                wordScore[i] += score[c - 'a'];
            }
        }

        dfs(0, avail, words, freq, wordScore, 0);
        return maxScore;
    }

    void dfs(int idx, vector<int>& avail, vector<string>& words,
             vector<vector<int>>& freq, vector<int>& wordScore,
             int currentScore) {

        if (idx == words.size()) {
            maxScore = max(maxScore, currentScore);
            return;
        }

        dfs(idx + 1, avail, words, freq, wordScore, currentScore);

        bool canTake = true;
        for (int c = 0; c < 26; c++) {
            if (freq[idx][c] > avail[c]) {
                canTake = false;
                break;
            }
        }

        if (canTake) {
            for (int c = 0; c < 26; c++) {
                avail[c] -= freq[idx][c];
            }

            dfs(idx + 1, avail, words, freq, wordScore,
                currentScore + wordScore[idx]);

            for (int c = 0; c < 26; c++) {
                avail[c] += freq[idx][c];
            }
        }
    }
};
