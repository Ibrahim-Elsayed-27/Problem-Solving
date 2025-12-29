class Solution {
    public int uniquePaths(int m, int n) {
            int total = m + n - 2;
            int k = Math.min(m - 1, n - 1); 
            long res = 1; 

            for (int i = 1; i <= k; i++) {
                res = res * (total - k + i) / i;
            }

            if (res > Integer.MAX_VALUE)
                throw new ArithmeticException("Overflow: result too large for int");

            return (int) res;
    }


}