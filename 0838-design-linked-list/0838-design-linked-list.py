class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None
        
class MyLinkedList:

    def __init__(self):
        self.obj = ListNode(-1)

    def get(self, index: int) -> int:
        ptr = self.obj
        for i in range(0, index+1):
            ptr = ptr.next
            if ptr is None:
                return -1
        return ptr.val

    def addAtHead(self, val: int) -> None:
        node = ListNode(val)
        node.next = self.obj.next
        self.obj.next = node

    def addAtTail(self, val: int) -> None:
        node = ListNode(val)
        ptr = self.obj
        while(ptr.next):
            ptr = ptr.next
        ptr.next = node

    def addAtIndex(self, index: int, val: int) -> None:
        ptr = self.obj
        for i in range(0, index):
            ptr = ptr.next
            if ptr is None:
                return
        node = ListNode(val)
        node.next = ptr.next
        ptr.next = node        

    def deleteAtIndex(self, index: int) -> None:
        ptr = self.obj
        for i in range(0, index):
            ptr = ptr.next
            if ptr is None:
                return
        temp = ptr.next
        if temp is None:
            return
        ptr.next = temp.next
        del temp

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)