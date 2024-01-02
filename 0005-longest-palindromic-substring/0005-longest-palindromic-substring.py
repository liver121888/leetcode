class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n == 1:
            return s
        dp = [[False] * n for _ in range(n)]# 2D array of n x n with all values set to False
        longest_palindrome = ""

        # single characters are palindromes
        for i in range(n):
            dp[i][i] = True
            longest_palindrome = s[i]

        # check substrings of length 2 and greater
        for length in range(2, n+1): # size of the window to check
            for i in range(n - length + 1): # iteration limit for the window
                j = i + length - 1 # end of the window
                if s[i] == s[j] and (length == 2 or dp[i+1][j-1]):
                    # dp[i+1][j-1] this evaluates to True if the substring between i and j is a palindrome
                    dp[i][j] = True # set the end points of the window to True
                    if length > len(longest_palindrome):
                        longest_palindrome = s[i:j+1] # update the longest palindrome

        return longest_palindrome