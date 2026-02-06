class Solution(object):
    def strStr(self, haystack, needle):
        if needle=="":
            return 0
        else:
            x=haystack.find(needle)
            return x
        