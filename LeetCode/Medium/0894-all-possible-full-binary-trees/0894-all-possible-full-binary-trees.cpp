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
    unordered_map<int, vector<TreeNode*>> memo;

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        // Full binary trees need odd number of nodes
        if (n % 2 == 0) return {};

        // Base case
        if (n == 1) {
            return { new TreeNode(0) };
        }

        // Memoized result
        if (memo.count(n)) return memo[n];

        vector<TreeNode*> result;

        // Split n-1 nodes between left and right
        for (int left = 1; left < n; left += 2) {
            int right = n - 1 - left;

            for (TreeNode* L : allPossibleFBT(left)) {
                for (TreeNode* R : allPossibleFBT(right)) {
                    TreeNode* root = new TreeNode(0);
                    root->left = L;
                    root->right = R;
                    result.push_back(root);
                }
            }
        }

        return memo[n] = result;
    }
};
