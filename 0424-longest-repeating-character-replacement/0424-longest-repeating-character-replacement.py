class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = collections.defaultdict(int)
        res = 0;
        l = 0
        for r in range(len(s)):
            # expand the window
            count[s[r]]+=1
            while (r - l + 1) - max(count.values()) > k:
                # not valid contract window
                count[s[l]]-=1
                l+=1
            
            res = max(res, r - l + 1)
        return res
            
            