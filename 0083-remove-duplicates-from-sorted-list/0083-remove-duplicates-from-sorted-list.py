# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        obj = ListNode(-1)
        ptr = obj
        ptr.next = head
        ptr = ptr.next

        while head:
            if head.val != ptr.val:
                ptr.next = head
                ptr = ptr.next
            head = head.next
        
        ptr.next = None
        return obj.next
        