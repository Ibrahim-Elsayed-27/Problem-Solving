class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int j = 0;
        for(char ref: strs[0]){
            for(int i = 1; i< strs.size(); ++i){
                if(ref != strs[i][j]){
                    return prefix;
                }
            }
            ++j;
            prefix += ref;
        }
        return prefix;
    }
};