# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if (not root):
            return False
        return self.dfs(root, targetSum)

    def dfs(self, root, targetSum) -> bool:
        if(not root):
            return False

        if(not root.left and not root.right and targetSum - root.val == 0):
            return True
        
        right = False
        left = False
        if(root.right):
            right = self.dfs(root.right, targetSum - root.val)
        
        if(right):
            return True
        if(root.left):
            left = self.dfs(root.left, targetSum - root.val)

        return left
            