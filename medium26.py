# sol 1
class MinStack(object):
    def __init__(self):
        self.stack = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        if not self.stack:
            self.min = val
            self.min_pos = 1
            self.stack.append([val, val])
            return

        min_val = min(self.stack[-1][1], val)
        self.stack.append([val, min_val])
        

    def pop(self):
        """
        :rtype: None
        """
        if self.stack: self.stack.pop()

    def top(self):
        """
        :rtype: int
        """
        return self.stack[-1][0] if self.stack else 0
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.stack[-1][1] if self.stack else 0
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()


