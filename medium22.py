# Solution 1 - sample
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None:
            return None
        ptr=head
        arr=[]
        while ptr is not None:
            arr.append(ptr.val)
            ptr=ptr.next
        arr.sort()
        n = ListNode(arr[0])
        head=n
        temp=head
        for i in range(1,len(arr)):
            n1 = ListNode(arr[i])
            temp.next=n1
            temp=temp.next       
        return head
        
           
# FAIL(unsuccessful in 30 minutes)
#  Solution 2
