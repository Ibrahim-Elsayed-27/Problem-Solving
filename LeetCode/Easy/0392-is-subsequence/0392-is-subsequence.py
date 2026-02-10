class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        def is_in_s(character):
            return character in s
        t = filter(is_in_s, t)
        t = "".join(t)
        #print(t)
        return s in t