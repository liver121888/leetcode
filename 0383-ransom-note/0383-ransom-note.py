class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        if len(ransomNote) > len(magazine):
            return False
        
        wordCount = {}
        
        # magazine is longer
        for c in ransomNote:
            if not wordCount.get(c):
                wordCount[c] = 1
            else:
                wordCount[c] += 1
        for c in magazine:
            if wordCount.get(c):
                wordCount[c] -= 1
        for c, n in wordCount.items():
            if n > 0:
                return False            
        return True
        