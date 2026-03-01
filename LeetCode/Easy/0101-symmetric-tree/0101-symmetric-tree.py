# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        left = self.inOrder(root.left, "")
        right = self.inOrderReverse(root.right, "")
        print(left, right)
        return left == right


    def inOrder(self, root, answer) -> str:
        if(root == None):
            answer += "n"
            return answer

        answer += f"{root.val}"
        answer = self.inOrder(root.left, answer)
        answer = self.inOrder(root.right, answer)

        return answer

    def inOrderReverse(self, root, answer) -> str:
        if(root == None):
            answer += "n"
            return answer

        answer += f"{root.val}"
        answer = self.inOrderReverse(root.right, answer)
        answer = self.inOrderReverse(root.left, answer)

        return answer
        


        
        