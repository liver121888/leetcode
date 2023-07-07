class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        n = len(answerKey)
        if n <= k:
            return n       

        left = 0
        tCnt = fCnt = 0
        maxSameKeyLen = 0
        for right in range(n):
            if answerKey[right] == 'T':
                tCnt += 1
            else:
                fCnt += 1
                
            if min(tCnt, fCnt) > k:
                maxSameKeyLen = max(maxSameKeyLen, right - left)
                if answerKey[left] == 'T':
                    tCnt -= 1
                else:
                    fCnt -= 1
                left += 1
        
        if min(tCnt, fCnt) <= k:
            maxSameKeyLen = max(maxSameKeyLen, tCnt+fCnt);

        return maxSameKeyLen