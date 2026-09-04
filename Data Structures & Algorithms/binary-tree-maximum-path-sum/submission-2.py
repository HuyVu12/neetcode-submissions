# Definition for a binary tree node.
#class TreeNode:
#    def __init__(self, val=0, left=None, right=None):
#        self.val = val
#        self.left = left
#        self.right = right

class Solution:
    def dfs(self, root: Optional[TreeNode]):
        root.ans = root.val
        curL = 0
        curR = 0
        if root.left != None: 
            self.dfs(root.left)
            curL = max(curL, root.left.val)
            root.ans = max(root.ans, root.left.ans)
        if root.right != None: 
            self.dfs(root.right)
            curR = max(curR, root.right.val)
            root.ans = max(root.ans, root.right.ans)
        root.mval = root.val + curL + curR
        root.val += max(curL, curR)
        root.ans = max(root.ans, root.mval)
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return root.ans