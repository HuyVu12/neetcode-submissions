# Definition for singly-linked list.
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:    
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        nums = []
        for li in lists:
            while li != None:
                nums.append(li.val)
                li = li.next
        nums.sort()
        if len(nums) == 0:
            return None
        last = ListNode(nums[-1])
        nums = nums[::-1]
        for i in range(1, len(nums)):
            cur = ListNode(nums[i], last)
            last = cur
        return last