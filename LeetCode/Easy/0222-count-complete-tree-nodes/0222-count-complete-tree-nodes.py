# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def __init__(self):
        self.counter = 0
    def countNodes(self, root: Optional[TreeNode]) -> int:
        self.counter = 0
        self.dfs(root)
        return self.counter

    def dfs(self,root):
        if(root == None):
            return 
        
        self.dfs(root.left)
        self.dfs(root.right)

        self.counter+=1
        return
    
        

