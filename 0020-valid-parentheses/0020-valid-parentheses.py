class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        pair = {')': '(', ']': '[', '}': '{'}

        for c in s:
            # Check if c is valid character
            if c not in "()[]{}":
                raise ValueError(f"Invalid character: {c}")

            if c in pair.values():  # left bracket
                st.append(c)
            else:  # right bracket
                if not st or st[-1] != pair[c]:
                    return False
                st.pop()

        return not st