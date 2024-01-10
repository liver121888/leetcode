class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []        
        
        sCnts = [0] * 26
        pCnts = [0] * 26
        ans = []
        
        for c in p:
            pCnts[ord(c) - ord('a')] += 1
        
        left = 0;
        for right in range(len(s)):
            # contract
            if right - left + 1 > len(p):
                sCnts[ord(s[left]) - ord('a')] -= 1
                left += 1
            
            sCnts[ord(s[right]) - ord('a')] += 1
            if sCnts == pCnts:
                ans.append(left)
        return ans
        