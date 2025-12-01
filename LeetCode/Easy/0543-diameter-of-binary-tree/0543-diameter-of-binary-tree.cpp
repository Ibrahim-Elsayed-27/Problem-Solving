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
        if(root == nullptr){
            return 0;
        }  
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        max_diameter = max(max_diameter, maxDepth(root->left) + maxDepth(root->right));
        return max_diameter;
    }



    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        else{
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};