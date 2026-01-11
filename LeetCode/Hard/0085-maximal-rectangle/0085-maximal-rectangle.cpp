class Solution {
public:
    vector<vector<int>> mat;
    vector<vector<int>> dp; // stores max rectangle area starting at (i,j)
    int M, N;

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        M = matrix.size();
        N = matrix[0].size();

        // convert char to int matrix
        mat.assign(M, vector<int>(N, 0));
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                mat[i][j] = matrix[i][j]-'0';

        // compute row-wise prefix widths
        for(int i=0;i<M;i++)
            for(int j=1;j<N;j++)
                if(mat[i][j]==1)
                    mat[i][j] += mat[i][j-1];

        // initialize DP with -1 (not computed)
        dp.assign(M, vector<int>(N, -1));

        int maxArea = 0;
        for(int i=0;i<M;i++)
            for(int j=0;j<N;j++)
                if(mat[i][j]>0)
                    maxArea = max(maxArea, dfs(i,j));

        return maxArea;
    }

    int dfs(int i, int j){
        if(i>=M || j>=N || mat[i][j]==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int width = mat[i][j];
        int minWidth = width;
        int maxArea = 0;

        // expand downward
        for(int k=i;k<M && mat[k][j]>0;k++){
            minWidth = min(minWidth, mat[k][j]);
            int height = k - i + 1;
            maxArea = max(maxArea, minWidth * height);
        }

        return dp[i][j] = maxArea;
    }
};