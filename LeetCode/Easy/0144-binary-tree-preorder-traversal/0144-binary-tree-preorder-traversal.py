# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def dfs_preorder(root, visited):
    if(not root):
        return 
    visited.append(root.val)
    dfs_preorder(root.left, visited)
    dfs_preorder(root.right, visited)
    
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        visited = []
        dfs_preorder(root, visited)
        return visited