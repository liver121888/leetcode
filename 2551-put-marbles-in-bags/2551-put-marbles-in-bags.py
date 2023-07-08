class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        # referencing solution
        n = len(weights)
        if k == 1 or k == n:
            return 0
        pair_weights = []
        for i in range(n - 1):
            pair_weights.append(weights[i] + weights[i + 1])
        pair_weights.sort()
        print(pair_weights)
        return sum(pair_weights[n - k:]) - sum(pair_weights[:k - 1])