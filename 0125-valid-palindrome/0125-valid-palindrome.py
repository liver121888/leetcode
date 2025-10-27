class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Read from the back and front at the same time
        # Skip any special character


        # race a car

        # l = 0, r = 9
        # l = 1, r = 8
        # l = 2, r = 7
        # l = 3, r = 6
        # l = 3, r = 5
        # return False
        
        # " "
        # l = 0, r = 0
        # return True

        l, r = 0, len(s) - 1
        while l < r:
            l_c = s[l]
            r_c = s[r]

            if not l_c.isalnum():
                l += 1
                continue
            
            if not r_c.isalnum():
                r -= 1
                continue

            if l_c.lower() != r_c.lower():
                return False

            l += 1
            r -= 1

        return True
        