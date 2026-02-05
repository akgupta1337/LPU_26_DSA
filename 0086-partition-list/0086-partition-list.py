# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lessThanX = ListNode(0)
        moreThanX = ListNode(0)

        ptr1 = lessThanX
        ptr2 = moreThanX

        while head:
            if head.val < x:
                ptr1.next = head
                ptr1 = ptr1.next
            else:
                ptr2.next = head
                ptr2 = ptr2.next

            head = head.next
        
        ptr1.next = moreThanX.next
        ptr2.next = None

        return lessThanX.next