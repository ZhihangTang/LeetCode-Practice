class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(list(filter(None,s.split(" ")))[::-1])