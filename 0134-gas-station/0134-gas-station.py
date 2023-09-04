class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n = len(gas)
        t_gas = 0
        cur_gas = 0
        ans = 0
        for i in range(n):
            t_gas += gas[i] - cost[i]
            cur_gas += gas[i] - cost[i]
            if cur_gas < 0:
                cur_gas = 0
                ans = i + 1
        return ans if t_gas >= 0 else -1