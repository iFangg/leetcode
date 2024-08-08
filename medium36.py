# Solution 1
class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        path = collections.defaultdict(int)
        mutation_path = [[startGene, 0]]
        path[startGene] = 1
        while mutation_path:
            curr, distance = mutation_path.pop(0)
            if curr == endGene:
                return distance
            for i in range(len(bank)):
                count = 0
                for j in range(8):
                    if curr[j] != bank[i][j]: count += 1
                if count == 1:
                    if path[bank[i]] == 0:
                        mutation_path.append([bank[i], distance + 1])
                        path[bank[i]] = 1

        return -1




# Solution 2
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        visit=set()
        geneset=set(["A","C","G","T"])
        q=deque()
        q.append([startGene,0])
        while q:
            gene,steps=q.popleft()
            if gene==endGene:
                return steps
            for i,g in enumerate(gene):
                for c in geneset:
                    if c!=g:
                        newgene=gene[:i]+c+gene[i+1:]
                        if newgene in bank and newgene not in visit:
                            visit.add(newgene)
                            q.append([newgene,steps+1])
        return -1

        
# Solution 3
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        if len(bank) == 0:
          return 0 if startGene == endGene else -1
        
        if endGene not in bank: return -1

        def dist(s,t):
            c = 0
            for i in range(len(s)):
                if s[i] != t[i]:
                    c += 1
            return c

        from collections import deque

        queue = deque([startGene])
        ans = 0
        used = set([startGene])
        d = {}
        for a in bank + [startGene]:
            for b in bank + [startGene]:
                if dist(a,b) == 1:
                    if a in d:
                        d[a].append(b)
                    else:
                        d[a] = [b]
                    if b in d:
                        d[b].append(a)
                    else:
                        d[b] = [a]
        
        while queue:
            l = len(queue)
            for _ in range(l):
                s = queue.popleft()
                if s == endGene:
                    return ans
                for nxt in bank:
                    if dist(nxt,s) == 1 and nxt not in used:
                        queue.append(nxt)
                        used.add(nxt)
            ans += 1

        return -1


