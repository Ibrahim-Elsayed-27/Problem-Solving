class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars_map;
        int max_length = 0;
        int left = 0;
        int right = 0;
        int size = s.length();

        while (right < size) {
            if (chars_map.find(s[right]) == chars_map.end() || chars_map[s[right]] < left) {
                chars_map[s[right]] = right;
                ++right;
                max_length = max(max_length, right - left);
            } else {
                left = chars_map[s[right]] + 1;
                chars_map[s[right]] = right;
                ++right;
            }
        }

        return max_length;
    }
};
