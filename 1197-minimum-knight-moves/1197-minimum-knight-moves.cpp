#include <unordered_map>
#include <algorithm>
#include <cmath>


// crazy solution
class Solution {
private:
    std::unordered_map<long long, int> memo;
    
    // Encode (x, y) pair into a single 64-bit integer for efficient hashing
    long long encode(int x, int y) {
        return (static_cast<long long>(x) << 32) ^ static_cast<unsigned int>(y);
    }
    
    int dfs(int x, int y) {
        // Work with absolute values to exploit symmetry
        x = std::abs(x);
        y = std::abs(y);
        
        // Create a unique key for memoization
        long long key = encode(x, y);
        
        // Check if result is already computed
        auto it = memo.find(key);
        if (it != memo.end()) {
            return it->second;
        }
        
        // Base cases
        if (x + y == 0) {
            return 0; // Already at target
        } else if (x + y == 2) {
            return 2; // Special case: need 2 moves (e.g., (1,1) or (2,0))
        }
        
        // Recursive case: try both possible moves and take the minimum
        int result = std::min(
            dfs(std::abs(x - 1), std::abs(y - 2)),
            dfs(std::abs(x - 2), std::abs(y - 1))
        ) + 1;
        
        // Store result in memoization table
        memo[key] = result;
        return result;
    }
    
public:
    int minKnightMoves(int x, int y) {
        // Start DFS from the target position (converted to first quadrant)
        return dfs(std::abs(x), std::abs(y));
    }
};
