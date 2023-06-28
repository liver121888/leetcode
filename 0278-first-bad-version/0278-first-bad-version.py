# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        if n == 1:
            return n if isBadVersion(n) else 0
        
        left,right = 0, n
        while left < right:
            mid=(right+left)//2
            if isBadVersion(mid):
                if isBadVersion(mid-1):
                    right = mid-1
                else:
                    return mid
            else:
                if isBadVersion(mid+1):
                    return mid+1
                else:
                    left=mid+1
        