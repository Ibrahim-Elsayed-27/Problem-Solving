# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

def dfs(root, current, paths):
    if(root == None):
        return 
    if(root.left == None and root.right == None):
        if(len(current) == 0):
            current += f"{root.val}"
        else:
            current += f"->{root.val}"
        paths.append(current)
        return
    if(len(current) == 0):
        current += f"{root.val}"
    else:
        current += f"->{root.val}"
    dfs(root.left, current, paths)
    dfs(root.right, current, paths)

class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        paths = []
        dfs(root, "", paths)
        return paths
        