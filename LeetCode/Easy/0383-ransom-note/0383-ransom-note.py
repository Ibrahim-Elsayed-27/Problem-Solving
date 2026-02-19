class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_dict = dict(Counter(magazine))

        for ch in ransomNote:
            if ch not in magazine_dict:
                return False
            else:
                magazine_dict[ch] -= 1
                if(magazine_dict[ch] <= 0):
                    magazine_dict.pop(ch)

        return True
        