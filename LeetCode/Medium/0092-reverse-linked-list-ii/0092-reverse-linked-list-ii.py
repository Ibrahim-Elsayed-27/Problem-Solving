# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def reverse_segment(start, end):
    prev = None
    curr = start
    stop = end.next

    while curr != stop:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt

    start.next = stop
    return prev
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if(head.next == None or left == right):
            return head
        if(head.next.next == None):
            print("hima")
            temp = head.next
            head.next = None
            temp.next = head
            return temp
        temp_head = head
        right -= left
        left -= 1
        #print(left,right)
        before_segment = None 
        while(left):
            before_segment = temp_head
            temp_head = temp_head.next
            left -= 1
        
        
        start_segment = temp_head
        #print("h", start_segment.val, before_segment.val)
        while(right):
            temp_head = temp_head.next
            right -= 1

        after_segment = temp_head.next
        end_segment = temp_head
        start_reversed_segment = reverse_segment(start_segment, end_segment)
        #print(start_reversed_segment.val, before_segment.val)
        if(before_segment):
            before_segment.next = start_reversed_segment
            return head
        else:
            return start_reversed_segment