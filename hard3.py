# Solution 1 - TOO SLOW
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        if endWord not in wordList: return []
        word_list = set(wordList)
        combinations = []
        queue = collections.deque([(beginWord, [beginWord])])
        visited = set([beginWord])
        min_dist = float('inf')

        while queue:
            localVisited = set()
            for _ in range(len(queue)):
                currWord, currPath = queue.popleft()
                # print(f"curr: {currWord}, {currPath}")
                found = False
                
                for i in range(len(beginWord)):
                    left = currWord[:i]
                    right = currWord[i + 1:]    

                    for c in string.ascii_lowercase:
                        new_word = left + c + right
                        if new_word in visited: continue
                        if new_word not in word_list: continue
                        
                        newPath = currPath + [new_word]
                        if new_word == endWord:
                            combinations.append(newPath)
                            min_dist = min(len(newPath), min_dist)
                            found = True
                            break
                        
                        localVisited.add(new_word)
                        queue.append((new_word, newPath))
                        # print(localVisited)
                    
                    if found: break
                
                if found: break

            word_list.discard(localVisited)
            visited.update(localVisited)

        # print(f"min distance: {min_dist}")
        return [path for path in combinations if len(path) == min_dist]
    


# Solution 2 - yield :O
    def findLadders(
        self, beginWord: str, endWord: str, wordList: List[str]
    ) -> List[List[str]]:
        def neighbors(word):
            for i in range(len(word)):
                for char in string.ascii_lowercase:
                    yield word[:i] + char + word[i + 1 :]

        i = 1
        words = {beginWord: lambda: [[beginWord]]}
        unvisited = set(wordList)
        while words and endWord not in words:
            i += 1
            new_words = defaultdict(lambda: lambda: [])
            for word in words:
                for new_word in neighbors(s):
                    if new_word in unvisited:

                        def get_seqs(capture=(new_word, new_words[new_word], words[word])):
                            new_word, nw_get_seqs, w_get_seqs = capture
                            seqs = nw_get_seqs()
                            for seq in w_get_seqs():
                                seq.append(new_word)
                                seqs.append(seq)
                            return seqs

                        new_words[new_word] = get_seqs
            words = new_words
            unvisited -= words.keys()
        return words[endWord]()
