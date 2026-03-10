# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.dfs(root, "")
        return self.sum
        

    def dfs(self, root, number):
        #print(number)
        #if(root == None):
            #self.sum += int(number)

        if(root.left):
            self.dfs(root.left, number + str(root.val))

        if(root.right):
            self.dfs(root.right, number + str(root.val))

        if(not root.right and not root.left):
            self.sum += int(number + str(root.val))