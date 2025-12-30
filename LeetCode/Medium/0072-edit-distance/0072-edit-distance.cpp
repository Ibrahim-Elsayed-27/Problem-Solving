class Solution {
public:
    int minDistance(string word1, string word2) {
        if(!word1.size() || !word2.size()){
            return abs((int)word1.size() - (int)word2.size());
        }
        vector<vector<int>> dp_arr(word1.size(), vector<int>(word2.size(), -1));
        return minDistance(word1, word2, 0, 0, dp_arr);

    }

    int minDistance(string& word1, string& word2, int m, int n, vector<vector<int>> &dp_arr){
        if(m == word1.size() || n == word2.size()){
            return (word1.size() - m) + (word2.size() - n);
        }
        int min_op = 0;
        if(word1[m] == word2[n]){
            min_op = minDistance(word1, word2, m+1, n+1, dp_arr);
        }
        else if(dp_arr[m][n] != -1){
            return dp_arr[m][n];
        }
        else{
            int insert_count = 1+minDistance(word1, word2, m, n+1, dp_arr);
            int delete_count = 1+minDistance(word1, word2, m+1, n, dp_arr);
            int replace_count = 1+minDistance(word1, word2, m+1, n+1, dp_arr);

            min_op =  min({insert_count, delete_count, replace_count});
            
        }
        dp_arr[m][n] = min_op;
        return min_op;
    }
};