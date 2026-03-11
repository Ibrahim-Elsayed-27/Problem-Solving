# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def depth_of_node(root, node, path=None):
    if path is None:
        path = []

    if root is None:
        return None

    path.append(root)

    if root == node:
        return path.copy()

    left = depth_of_node(root.left, node, path)
    if left is not None:
        return left

    right = depth_of_node(root.right, node, path)
    if right is not None:
        return right

    path.pop()
    return None
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        p_path = depth_of_node(root, p)
        q_path = depth_of_node(root, q)
        i = 0
        while(i < len(p_path) and i < len(q_path)):
            if p_path[i] != q_path[i]:
                return p_path[i - 1]
            
            i += 1

        if(i == len(p_path)):
            return p_path[-1]
        else:
            return q_path[-1]
        
        
        



