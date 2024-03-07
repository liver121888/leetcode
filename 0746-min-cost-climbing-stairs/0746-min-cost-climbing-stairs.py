class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        #         n = len(cost)
        #         dp = [-1 for c in range(n + 1)]

        #         def dfs(i):
        #             if i == 0 or i == 1:
        #                 dp[i] = cost[i]
        #                 return cost[i]

        #             if dp[i] != -1:
        #                 return dp[i]

        #             if i - 1 >= 0:
        #                 c1 = dfs(i - 1)
        #             if i - 2 >= 0:
        #                 c2 = dfs(i - 2)

        #             if i != n:
        #                 dp[i] = cost[i] + min(c1, c2)
        #             else:
        #                 dp[i] = min(c1, c2)

        #             return dp[i]

        #         return dfs(n)
        
        for i in range(len(cost) - 3, -1, -1):
            cost[i] += min(cost[i + 1], cost[i + 2])

        return min(cost[0], cost[1])
        
        