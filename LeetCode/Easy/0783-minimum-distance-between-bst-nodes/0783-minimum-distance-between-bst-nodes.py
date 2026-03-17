# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.min_dist = sys.maxsize
        self.sorted_list_bst = []

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        for i in range(len(self.sorted_list_bst) -1):
            if(self.sorted_list_bst[i+1] - self.sorted_list_bst[i] < self.min_dist):
                self.min_dist = self.sorted_list_bst[i+1] - self.sorted_list_bst[i]
        
        return self.min_dist

    def dfs(self, root):
        if root == None:
            return 
        
        if(root.left):
            self.dfs(root.left)
        self.sorted_list_bst.append(root.val)
        if(root.right):
            self.dfs(root.right)



                  

        


