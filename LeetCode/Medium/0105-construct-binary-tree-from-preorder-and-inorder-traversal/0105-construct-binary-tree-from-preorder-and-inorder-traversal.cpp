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

        if (k > inL && preL + 1 <= preR) {
            int leftVal = pre[preL + 1];
            bool existsLeft = false;
            for (int i = inL; i < k; i++) {
                if (in[i] == leftVal) {
                    existsLeft = true;
                    break;
                }
            }
            if (existsLeft) {
                int leftSize = k - inL;
                root->left = build(pre, in,
                                   preL + 1, preL + leftSize,
                                   inL, k - 1);
            }
        }

        if (k < inR) {
            bool foundRight = false;
            int rightVal = 0;
            int rightIndex = -1;

            for (int x = preL + 1; x <= preR && !foundRight; x++) {
                for (int j = k + 1; j <= inR; j++) {
                    if (pre[x] == in[j]) {
                        rightVal = pre[x];
                        rightIndex = x;
                        foundRight = true;
                        break;
                    }
                }
            }

            if (foundRight) {
                int rightSize = inR - k;
                root->right = build(pre, in,
                                    rightIndex, preR,
                                    k + 1, inR);
            }
        }

        return root;
    }

};
