class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        std::vector<int> s_chars_occ(26,0);
        std::vector<int> t_chars_occ(26,0);
        for(char s_char:s){
            s_chars_occ[s_char - 97]++;
        }
        for(char t_char:t){
            t_chars_occ[t_char - 97]++;
        }

        return (s_chars_occ == t_chars_occ);
    }
};