# Solution 1
#   Definition for singly-linked list.
  # class ListNode:
  #     def __init__(self, val=0, next=None):
  #         self.val = val
  #         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if n == 1 and head.next == None: return None
        length = 0
        front = head
        while head != None:
            length += 1
            head = head.next

        count = length
        head = front
        prev = head
        while head != None:
            if count == n:
                if n == length: front = head.next
                prev.next = head.next
                head.next = None
                head = prev.next
                count -= 1
                continue
            count -= 1
            prev = head
            head = head.next
        

        return front



# Solution 2
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast=head
        slow=head
        while n!=0 and fast!=None:
            fast=fast.next
            n-=1
        prev=None
        while fast!=None:
            prev=slow
            slow=slow.next
            fast=fast.next
        if prev==None and slow!=None:
            return slow.next
        elif prev==None:
            return None
        prev.next=slow.next
        del slow
        return head
