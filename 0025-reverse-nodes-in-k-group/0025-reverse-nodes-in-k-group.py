# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def kthNode(self, head, k):
        while(head and k != 1):
            head = head.next
            k -= 1
        return head
    def reverse(self, head):
        curr = head
        prev = nxt = None
        while curr:
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
        return prev
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        ptr = head
        prev = None
        ans = None
        while ptr:
            kth = self.kthNode(ptr, k)
            if ans is None:
                ans = kth
            if kth is None:
                if prev:
                    prev.next = ptr
                    return ans
                return head

            nxt = kth.next
            kth.next = None
            self.reverse(ptr)
            if prev:
                prev.next = kth
            prev = ptr
            ptr = nxt

        return ans