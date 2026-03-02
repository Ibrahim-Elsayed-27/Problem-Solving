# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        queue = deque()
        queue.append(root)
        sum_level = 0
        len_level = 0
        answer = []
        while(queue):
            len_level = len(queue)
            for _ in range(len_level):
                current = queue.popleft()
                sum_level += current.val
                if(current.left is not None):
                    queue.append(current.left)
                if(current.right is not None):
                    queue.append(current.right)

            answer.append(sum_level / len_level)
            sum_level = 0

        return answer
                        





        