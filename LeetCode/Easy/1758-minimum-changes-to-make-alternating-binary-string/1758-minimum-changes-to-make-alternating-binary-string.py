class Solution:
    def minOperations(self, s: str) -> int:
        start_one = 0
        start_zero = 0
        for i in range(len(s)):
            temp_one = ('1' if i % 2 ==0 else '0')
            temp_zero = ('0' if i % 2 ==0 else '1')
            if(temp_one == s[i]):
                start_one += 1
            else:
                start_zero += 1

        return min(start_one, start_zero)
        