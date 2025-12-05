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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
;
    }

    TreeNode* build(vector<int>& pre, vector<int>& in,
                    int preL, int preR, int inL, int inR) {

        if (preL > preR || inL > inR)
            return nullptr;

        int rootVal = pre[preL];
        TreeNode* root = new TreeNode(rootVal);

        int k = inL;
        while (k <= inR && in[k] != rootVal) k++;

        int leftSize = k - inL;

        if (leftSize > 0) {
            root->left = build(pre, in,
                               preL + 1,
                               preL + leftSize,
                               inL,
                               k - 1);
        }

        int rightIndex = preL + 1 + leftSize;

        if (rightIndex <= preR) {
            root->right = build(pre, in,
                                rightIndex,
                                preR,
                                k + 1,
                                inR);
        }

        return root;
    }

};
