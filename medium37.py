# Solution 1
class Solution:
    def reverseWords(self, s: str) -> str:
        sentence = s.strip().rstrip(' ')
        if len(sentence.split()) <= 1: return sentence
        return ' '.join(reversed(sentence.split()))



# Solution 2
    def reverseWords(self, s: str) -> str:
        x = s.split()
        return " ".join(x[::-1])
