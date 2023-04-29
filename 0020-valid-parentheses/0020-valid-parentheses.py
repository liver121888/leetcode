class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for ch in s:
            if len(stack) == 0:
                stack.append(ch)
            else:
                if ord(stack[-1]) == ord(ch) - 1 or ord(stack[-1]) == ord(ch) - 2:
                    stack.pop()
                else:
                    stack.append(ch)
        if len(stack) == 0:
            return True
        else:
            return False