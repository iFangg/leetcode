# Solution 1 - bfs (slow but memory efficient)
import collections

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def getHeight(self, node):
        if not node:
            return 0
        left_height = self.getHeight(node.left)
        right_height = self.getHeight(node.right)
        return 1 + max(left_height, right_height)

    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True

        left_height = self.getHeight(root.left)
        right_height = self.getHeight(root.right)

        if abs(left_height - right_height) > 1: return False

        return self.isBalanced(root.left) and self.isBalanced(root.right)


# Solution 2 - dfs (faster but slightly less memory efficient)
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        balanced = [True]
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            if(abs(left-right) > 1):
                balanced[0] = False
            return 1+max(left, right)
        
        dfs(root)
        return balanced[0]
