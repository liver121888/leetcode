class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 48-57: 0-9, 65-90: A-Z, 97-122: a-z
        s = s.lower()
        end = len(s) - 1
        start = 0
        while start <= end:
            if not s[start].isalnum():
                start += 1
            elif not  s[end].isalnum():
                end -= 1
            elif s[start] == s[end]:
                start += 1
                end -= 1
            else:
                return False                  
        return True