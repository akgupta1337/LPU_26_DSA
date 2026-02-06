class ListNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.cap = capacity
        self.map = {}
        self.left = ListNode(0, 0)
        self.right = ListNode(0, 0)
        
        self.left.next = self.right
        self.right.prev = self.left

    def delete(self, node):
        prev = node.prev
        nxt = node.next
        prev.next = nxt
        nxt.prev = prev

    def insert(self, node):
        nxt = self.left.next

        self.left.next = node
        node.prev = self.left

        nxt.prev = node
        node.next = nxt

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1

        node = self.map[key]
        self.delete(node)
        self.insert(node)
        return node.val

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            node = self.map[key]
            node.val = value
            self.delete(node)
            self.insert(node)
            return
        if len(self.map) == self.cap:
            node = self.right.prev
            self.delete(node)
            del self.map[node.key]
        node = ListNode(key, value)
        self.map[key] = node
        self.insert(node)


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)