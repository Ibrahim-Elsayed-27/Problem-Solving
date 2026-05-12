class Solution:
    def mirrorDistance(self, n: int) -> int:
        str_n = str(n)
        str_n_reversed = str_n[::-1]
        reversed_n = int(str_n_reversed)
        return abs(n - reversed_n)