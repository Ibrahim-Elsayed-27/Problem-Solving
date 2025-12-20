class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal_triangle;
        pascal_triangle.push_back(vector<int>{1});
        for(int i =1; i<numRows; ++i){
            pascal_triangle.push_back(vector<int>{1});
            for(int j =1; j<i; ++j){
                pascal_triangle[i].push_back(pascal_triangle[i-1][j] + pascal_triangle[i-1][j-1]);
            }

            pascal_triangle[i].push_back(1);
        }
        return pascal_triangle;
    }
};