# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs (root, listed_tree) -> list:
    if not root:
        return 
    listed_tree.append(root)
    dfs(root.left, listed_tree)
    dfs(root.right, listed_tree)
    return listed_tree
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return 
        listed_tree = []
        listed_tree = dfs(root, listed_tree)
        for i in range(len(listed_tree) - 1):
            listed_tree[i].left = None
            listed_tree[i].right = listed_tree[i+1]