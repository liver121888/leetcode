class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1;
        
        totalVariations = 0     
        num2Steps = 0
        while num2Steps <= n//2:
            num1Steps = n - num2Steps*2
            totalVariations += (math.factorial(num1Steps + num2Steps) 
                                // (math.factorial(num2Steps) * math.factorial(num1Steps)))
            num2Steps+=1
            
        return totalVariations
        
        