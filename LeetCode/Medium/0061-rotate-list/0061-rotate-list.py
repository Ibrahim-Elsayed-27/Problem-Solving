# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:


        len_list = 0
        temp = head
        while(temp):
            len_list+=1
            temp = temp.next
        
        if(len_list < 2 or k==0 or k%len_list == 0):
            return head
        k = k%len_list
        
        
        start = head 
        k_backward = head
        end_list = head
        for i in range(len_list - k - 1):
            end_list = end_list.next

        k_backward = end_list.next
        end_list.next = None
        temp_head = head
        head = k_backward
        print(end_list.val, k)

        while(k_backward.next):
            k_backward = k_backward.next
        
        k_backward.next = temp_head

        return head

        

        