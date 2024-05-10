# Solution 1
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        tens = 1
        first = 0
        second = 0
        while l1 != None:
            first += l1.val * tens
            tens *= 10
            l1 = l1.next
        
        tens = 1
        while l2 != None:
            second += l2.val * tens
            tens *= 10
            l2 = l2.next
        
        node_sum = str(first + second)
        head = ListNode(int(node_sum[-1]), None)
        curr = head
        for i in range(len(node_sum) - 2, -1, -1):
            node = ListNode(int(node_sum[i]))
            curr.next = node
            curr = curr.next
        
        return head


# Solution 2
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        p1, p2 = l1, l2
        carry = 0
        res_dummy = ListNode(-1)
        res_curr = res_dummy.next
        res_prev = res_dummy

        while p1 or p2:

            if not p1:
                # only p2 is left
                sum_ = p2.val + carry
                p2 = p2.next

            elif not p2:
                # only p1 is left
                sum_ = p1.val + carry
                p1 = p1.next
            
            else:
                sum_ = p1.val + p2.val + carry
                p1 = p1.next
                p2 = p2.next
            
            new_node = ListNode(sum_ % 10)
            carry = sum_ // 10
            
            
            res_prev.next = new_node
            res_prev = res_prev.next
        
        
        if carry:
            new_node = ListNode(carry)
            res_prev.next = new_node
            res_prev = res_prev.next

        
        return res_dummy.next
    

