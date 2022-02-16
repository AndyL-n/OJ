"""
author: L
date: 2022/2/16 15:50
"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode(0)
        cur = ans
        sum = 0
        while (l1 or l2 or sum):
            if (l1):
                sum += l1.val
                l1 = l1.next
            if (l2):
                sum += l2.val
                l2 = l2.next

            cur.next = ListNode(sum % 10)
            sum = int((sum - sum % 10) / 10)
            cur = cur.next

        return ans.next