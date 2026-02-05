class Solution:
    def isPalindrome(self, s: str) -> bool:
        alpha_s_list = []
        for char in s:
            if (char.isalnum()):
                alpha_s_list.append(char.lower())

        alpha_s = "".join(alpha_s_list)
        print(alpha_s)
        alpha_s_list.reverse()
        return alpha_s == "".join(alpha_s_list)
        