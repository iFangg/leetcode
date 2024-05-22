# Solution 1
class Solution:
    def backtrack(self, n, curr, open_b, closed_b, results):
        if len(curr) == n * 2:
            results.add(curr)
            return results
        
        # if not max (, test ( and )
        # if at max ( but not max ), add )
        if open_b < n:
            self.backtrack(n, curr + "(", open_b + 1, closed_b, results)
            self.backtrack(n, curr + ")", open_b, closed_b + 1, results) if open_b > closed_b else None
        elif closed_b < n:
            self.backtrack(n, curr + ")", open_b, closed_b + 1, results)

        return results

    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1: return ["()"]

        return self.backtrack(n, "(", 1, 0, set())
        


# Solution 2
    def generateParenthesis(self, n: int) -> List[str]:
        def dfs(open, close,s):
            if len(s)==n*2:
                res.append(s)
                return
            
            if open<n:
                dfs(open+1,close, s + '(')
            if close<open:
                dfs(open, close+1, s + ')')
        
        res=[]
        dfs(0,0,'')
        return res
