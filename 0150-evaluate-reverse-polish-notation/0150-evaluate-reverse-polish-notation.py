class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for token in tokens:
            if token == "+":
                st.append(st.pop() + st.pop())
            elif token == "-":
                t2 = st.pop()
                t1 = st.pop()
                st.append(t1 - t2)
            elif token == "*":
                st.append(st.pop() * st.pop())
            elif token == "/":
                t2 = st.pop()
                t1 = st.pop()
                st.append(int(t1 / t2));                
            else:
                # numbers
                st.append(int(token))
                
        return st[0]