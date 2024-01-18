class Solution:
    def climbStairs(self, n: int) -> int:

        num1Steps, num2Steps = 1, 1
        for i in range(n - 1):
            temp = num1Steps
            num1Steps = num1Steps + num2Steps
            num2Steps = temp
            
        return num1Steps
        
        