# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        val = []
        while head:
            val.append(head.val);
            head = head.next;
        if len(val) == 0:
            return None
        root = ListNode(val.pop())
        cur = root
        while len(val):
            cur.next = ListNode(val.pop())
            cur = cur.next
        return root
        