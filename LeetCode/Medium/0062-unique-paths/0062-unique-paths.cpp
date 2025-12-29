class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        
        return dfs(m-1,n-1, dp);
    }

    int dfs(int m, int n, vector<vector<int>>& dp){
        if(!m && !n){
            return 1;
        }
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        int paths_down = 0; 
        if(m>0){
            paths_down += dfs(m-1,n, dp);
        } 
        int paths_left = 0;
        if(n>0){
            paths_left += dfs(m,n-1, dp);
        } 
        dp[m][n] = paths_down+paths_left;
        return paths_down+paths_left;
    }
};