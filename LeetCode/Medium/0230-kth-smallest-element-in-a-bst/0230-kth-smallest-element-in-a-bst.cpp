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
    vector<int> tree;
    int kth;
    int kthSmallest(TreeNode* root, int k) {
        kth = k;
        return dfs(root);
    }

    int dfs(TreeNode* root){
        if(!root) return -1 ;
        int left = dfs(root->left);
        if(left != -1) return left;
        --kth;
        if(kth == 0) return root->val;
        int right = dfs(root->right);
        if(right != -1) return right;
        return -1;
    }
};