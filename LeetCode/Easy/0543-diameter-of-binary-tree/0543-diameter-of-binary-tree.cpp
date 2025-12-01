/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int max_diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
            dfs(root);
            return max_diameter;
    }


    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left_height = dfs(node->left);
        int right_height = dfs(node->right);

        max_diameter = max(max_diameter, left_height + right_height);

        return 1 + max(left_height, right_height);  
    }

};