class MyStack:

    def __init__(self):
        self.q1 = collections.deque()
        self.q2 = collections.deque()
        

    def push(self, x: int) -> None:
        self.q1.append(x)

    def pop(self) -> int:
        while self.q1:
            self.q2.append(self.q1.popleft())
            
            
        x = self.q2.pop()
        
        while self.q2:
            self.q1.append(self.q2.popleft())
        return x        

    def top(self) -> int:
        return self.q1[-1]

    def empty(self) -> bool:
        return True if len(self.q1) == 0 else False 


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()