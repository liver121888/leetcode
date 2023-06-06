class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        table = [0] * 26
        for c in s:
            table[ord(c) - ord('a')] += 1
        for c in t:
            table[ord(c) - ord('a')] -= 1
        for n in table:
            if n != 0:
                return False       
        return True