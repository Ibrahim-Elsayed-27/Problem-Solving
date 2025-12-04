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
        dfs(root);
        return tree[k-1];
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        tree.push_back(root->val);
        --kth;
        if(kth == 0) return;
        dfs(root->right);
    }
};