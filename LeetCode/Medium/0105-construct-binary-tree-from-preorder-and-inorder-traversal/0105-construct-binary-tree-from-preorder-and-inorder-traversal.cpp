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
        if (preorder.empty() || inorder.empty())
            return nullptr;

        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        int k = 0;
        while (k < inorder.size() && inorder[k] != rootVal) k++;

        if (k > 0 && preorder.size() > 1) {
            int leftVal = preorder[1];
            bool existsLeft = false;
            for (int i = 0; i < k; i++) {
                if (inorder[i] == leftVal) {
                    existsLeft = true;
                    break;
                }
            }
            if (existsLeft) {
                vector<int> newPre(preorder.begin() + 1, preorder.end());
                vector<int> newIn(inorder.begin(), inorder.begin() + k);
                root->left = buildTree(newPre, newIn);
            }
        }

        if (k < inorder.size() - 1) {
            bool foundRight = false;
            int rightVal = 0;

            for (int x = 1; x < preorder.size() && !foundRight; x++) {
                for (int j = k + 1; j < inorder.size(); j++) {
                    if (preorder[x] == inorder[j]) {
                        rightVal = preorder[x];
                        foundRight = true;
                        break;
                    }
                }
            }

            if (foundRight) {
                int pos = 0;
                while (pos < preorder.size() && preorder[pos] != rightVal) pos++;

                vector<int> newPre(preorder.begin() + pos, preorder.end());
                vector<int> newIn(inorder.begin() + k + 1, inorder.end());
                root->right = buildTree(newPre, newIn);
            }
        }

        return root;
    }
};
