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
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> order_traversal;
    vector<vector<int>> result;
    if(root) order_traversal.push(root);
    vector<int> level;
    int level_size;
    bool zigzag = false;
    while(!order_traversal.empty()){
        level_size = order_traversal.size();
        int i = 0;
        vector<int> level;
        while(i < level_size){
            TreeNode* temp = order_traversal.front();
            order_traversal.pop();
            level.push_back(temp->val);
            if(temp->left != nullptr){
                order_traversal.push(temp->left);
            }
            if(temp->right != nullptr){
                order_traversal.push(temp->right);
            }
            ++i;
        }
        if(zigzag){
            reverse(level.begin(), level.end());
        }
        zigzag = !zigzag;

        result.push_back(level);
    }

    return result;
}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root);
    }
};