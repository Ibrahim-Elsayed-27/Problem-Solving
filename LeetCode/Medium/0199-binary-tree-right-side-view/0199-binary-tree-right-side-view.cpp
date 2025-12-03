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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> order_traversal;
        if(root) order_traversal.push(root);
        int level_size;
        vector<int> level;
        while(!order_traversal.empty()){
            level_size = order_traversal.size();
            int i = 0;
            while(i < level_size){
                TreeNode* temp = order_traversal.front();
                order_traversal.pop();
                if(i == level_size - 1){
                    level.push_back(temp->val);
                } 
                if(temp->left != nullptr){
                    order_traversal.push(temp->left);
                }
                if(temp->right != nullptr){
                    order_traversal.push(temp->right);
                }
                ++i;
            }
        }

        return level;
    }
};