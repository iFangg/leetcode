# Solution 1
class Solution:
    def create_map(self, end, words):
        wm = collections.defaultdict(set)
        visited = []
        word_len = len(words[0])
        for curr in words:
            if curr == end: continue
            for w in words:
                if w == curr: continue
                delta = 0
                for i in range(word_len):
                    if delta > 1: break
                    if w[i] != curr[i]: delta += 1
                if delta != 1: continue
                wm[curr].add(w)
            
        # print(wm)
        return wm

    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList: return 0
        wordList.insert(0, beginWord)
        word_map = self.create_map(endWord, wordList)
        if not word_map: return 0

        q = collections.deque()
        visited = set()
        q.append(beginWord)
        visited.add(beginWord)
        pred = collections.defaultdict(str)

        while q:
            curr = q.popleft()

            if curr == endWord:
                count = 0
                while curr != beginWord:
                    count += 1
                    curr = pred[curr]
                count += 1
                return count

            for w in word_map[curr]:
                if w not in visited:
                    visited.add(w)
                    pred[w] = curr
                    q.append(w)
        
        return 0


# Solution 2
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)

        if endWord not in wordSet:
            return 0

        beginSet = {beginWord}
        endSet = {endWord}
        distance = 1

        while beginSet and endSet:
            wordSet -= beginSet
            distance += 1
            newSet = set()

            for word in beginSet:
                for i in range(len(word)):
                    left = word[:i]
                    right = word[i + 1:]

                    for c in string.ascii_lowercase:
                        new_word = left + c + right

                        if new_word in wordSet:
                            if new_word in endSet:
                                return distance
                            newSet.add(new_word)

            if len(beginSet) > len(endSet): #swap to lowest set
                beginSet = endSet
                endSet = newSet
            else: beginSet = newSet

        return 0
        
