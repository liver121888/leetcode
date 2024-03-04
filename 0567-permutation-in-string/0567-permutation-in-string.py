class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        cnt1 = Counter(s1)
        l = 0
        # initialize counter
        cnt2 = Counter()

        for r in range(len(s2)):
            cnt2[s2[r]] += 1
            
            if r - l + 1 > n1:
                # contract
                cnt2[s2[l]] -= 1
                l += 1
            
            if cnt2 == cnt1:
                return True
        return False
            
                
                