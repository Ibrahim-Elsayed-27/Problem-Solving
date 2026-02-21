class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapping_dict = {}
        t_choosen_chars = set()
        for i in range(len(s)):
            if s[i] in mapping_dict:
                if t[i] != mapping_dict[s[i]]:
                    return False
            else:
                if t[i] in t_choosen_chars:
                    return False
                mapping_dict[s[i]] = t[i]
                t_choosen_chars.add(t[i])

        return True