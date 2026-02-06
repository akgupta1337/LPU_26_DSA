# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-101)
        prev = dummy
        ptr = dummy

        while head:
            if head.val != ptr.val:
                ptr.next = head
                prev = ptr
                ptr = ptr.next
                head = head.next
            else:
                while head and ptr.val == head.val:
                    head = head.next
                ptr = prev
        ptr.next = None
        return dummy.next

        