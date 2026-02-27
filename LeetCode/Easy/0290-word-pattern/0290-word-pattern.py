class Solution:
    def wordPattern(self, s: str, t: str) -> bool:
        mapping_dict = {}
        t = t.split()
        t_choosen_words = set()
        if(len(s) != len(t)):
            return False
        for i in range(len(s)):
            if s[i] in mapping_dict:
                if t[i] != mapping_dict[s[i]]:
                    return False
            else:
                if t[i] in t_choosen_words:
                    return False
                mapping_dict[s[i]] = t[i]
                t_choosen_words.add(t[i])

        return True