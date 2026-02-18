class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n_bin = bin(n)[2:]
        for i in range(len(n_bin)-1):
            if(n_bin[i] == n_bin[i+1]):
                return False
        return True