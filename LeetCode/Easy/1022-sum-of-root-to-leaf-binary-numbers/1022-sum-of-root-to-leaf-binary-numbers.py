# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, "")
        return self.sum

    def dfs(self, root, num):
        if (root.left == None and root.right == None):
            num = num + f"{root.val}"
            self.sum += int(num, 2)
            return
        num = num + f"{root.val}"
        if(root.left):       
            self.dfs(root.left, num)
        if(root.right):
            self.dfs(root.right, num)



        