class Solution:
    def hammingWeight(self, n: int) -> int:
        bin_str =  str(bin(n))  
        bin_str = bin_str[2:]
        ones = 0
        for num in bin_str:
            if num == "1":
                ones +=1

        return ones