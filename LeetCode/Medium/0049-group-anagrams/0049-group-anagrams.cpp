class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> words_freq_map;
        for(string word: strs){
            string copy = word;
            sort(word.begin(), word.end());
            words_freq_map[word].push_back(copy);
        }

        vector<vector<string>> result;
        for(auto& [key, group]: words_freq_map){
            result.push_back(group);
        }
        return result;
    }
};