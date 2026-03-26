"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
def bfs(root):
    bfs_queue = []
    result_list = []
    bfs_queue.append(root)
    while(bfs_queue):
        result_list.append(list(bfs_queue))
        temp_queue = bfs_queue
        bfs_queue = []
        while(temp_queue):
            current = temp_queue.pop(0)
            if(current.left):
                bfs_queue.append(current.left)
            if(current.right):
                bfs_queue.append(current.right)

    return result_list


class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if(root):
            bfs_list = bfs(root)
            for level in bfs_list:
                for i in range(len(level)-1):
                    level[i].next = level[i+1]

        return root
                


        