# FAIL(unsuccessful in 30 minutes)
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
        
           
#  Solution 2
class Solution(object):
    def sortList(self, head):
        curr = head
        l = []
        while curr:
            l.append(curr.val)
            curr = curr.next
        l.sort()
        curr = head
        for i in l:
            curr.val = i
            curr = curr.next
        return head


# Solution 3 - Merge Sort
class Solution(object):
    def getMiddle(self, head):
        slow, fast = head, head

        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        return slow

    def merge(self, left, right):
        dummy = ListNode()
        current = dummy

        while left and right:
            if left.val < right.val:
                current.next = left
                left = left.next
            else:
                current.next = right
                right = right.next

            current = current.next

        # If one of the lists is not empty, append the remaining nodes
        current.next = left or right

        return dummy.next

    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None: return head
        # Split the linked list into two halves
        middle = self.getMiddle(head)
        second_half = middle.next
        middle.next = None

        # Recursively sort the two halves
        left = self.sortList(head)
        right = self.sortList(second_half)

        # Merge the sorted halves
        return self.merge(left, right)
