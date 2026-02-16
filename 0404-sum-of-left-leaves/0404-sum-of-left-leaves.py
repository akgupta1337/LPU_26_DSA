# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sum(self, root, flag):
        if root is None:
            return 0

        if root.left is None and root.right is None and flag:
            return root.val

        lsum = self.sum(root.left, True)
        rsum = self.sum(root.right, False)

        return lsum + rsum

    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        return self.sum(root, False)
