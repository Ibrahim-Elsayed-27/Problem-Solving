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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else{
            //case no children
            if(!root->left && !root->right){
                delete root;
                return nullptr;
            }
            //case right child only
            else if(!root->left && root->right){
                TreeNode* temp = root;
                root = root->right;
                delete temp;
            }
            //case left child only
            else if(root->left && !root->right){
                TreeNode* temp = root;
                root = root->left;
                delete temp;
            }
            //case both children exist
            else if(root->left && root->right){
                TreeNode* successor  = inorderSuccessor(root->right);   
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
        

    }




    TreeNode* inorderSuccessor(TreeNode* root){
        if(!root) return root;
        if(!root->left) return root;
        return inorderSuccessor(root->left);
    }

  
};