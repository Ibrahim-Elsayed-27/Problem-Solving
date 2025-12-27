class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(string, int, int)> backtrack = [&](string current, int open, int close) {
            if (open == 0 && close == 0) {
                result.push_back(current);
                return;
            }

            if (open > 0) {
                backtrack(current + '(', open - 1, close);
            }

            if (close > open) {
                backtrack(current + ')', open, close - 1);
            }
        };

        backtrack("", n, n);
        return result;
    }
};
