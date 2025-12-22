class Solution {
public:
    int maxRepeating(string sequence, string word) {
        vector<int> seq_dp(sequence.size(), -1);
        int max_count = 0;
        int count = 0;
        for (int k = 0; k < sequence.size(); ++k) {
            for (int i = k; i < sequence.size(); ++i) {
                bool flag = true;
                if (seq_dp[i] == -1) {
                    for (int j = 0; j < word.size(); ++j) {
                        if (sequence[i + j] != word[j]) {
                            count = 0;
                            seq_dp[i] = 0;
                            flag = false;
                            break;
                        }
                    }

                    if (flag) {
                        ++count;
                        max_count = (max_count < count ? count : max_count);
                        seq_dp[i] = 1;
                        i += word.size() - 1;
                    }
                } else if (seq_dp[i] == 0) {
                    i += word.size() - 1;
                    count = 0;
                } else {
                    ++count;
                    max_count = (max_count < count ? count : max_count);
                    i += word.size() - 1;
                }
            }

            count = 0;
        }

        return max_count;
    }
};