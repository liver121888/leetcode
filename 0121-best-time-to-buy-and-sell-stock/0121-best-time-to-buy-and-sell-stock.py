class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        minP = 100000
        for p in prices:
            if p < minP:
                minP = p
            curProfit = p - minP
            if curProfit > profit:
                profit = curProfit
        return profit