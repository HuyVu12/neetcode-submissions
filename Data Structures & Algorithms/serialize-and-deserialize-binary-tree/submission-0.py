# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:

    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        if root == None:
            return " 2000"
        ans = (" " + str(root.val))
        ans += self.serialize(root.left)
        ans += self.serialize(root.right)
        return ans
        
    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        data = list(map(int, data.split()))
        data = data[::-1]
        if len(data) == 1:
            return None
        root = TreeNode(data.pop())
        def dfs(node: Optional[TreeNode]):
            val = data.pop()
            if val != 2000:
                nodeL = TreeNode(val)
                dfs(nodeL)
                node.left = nodeL
            val = data.pop()
            if val != 2000:
                nodeR = TreeNode(val)
                dfs(nodeR)
                node.right = nodeR
        dfs(root)
        return root
            
        



