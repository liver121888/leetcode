class Solution:
    def longestPalindrome(self, s: str) -> int:
        if len(s) == 1:
            return 1
        
        countMap = Counter(s)
        maxLength = 0
        isFirstOdd = True
        
        for cnt in countMap.values():
            if cnt % 2 == 0:
                maxLength += cnt
            else:
                if isFirstOdd:
                    maxLength += cnt
                    isFirstOdd = False
                else:
                    maxLength += cnt - 1

        return maxLength
            