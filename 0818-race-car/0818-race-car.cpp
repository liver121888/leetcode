#include <queue>
#include <set>
#include <string>
#include <tuple>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        // BFS 隊列: 存儲 {position, speed}
        queue<pair<int, int>> q;
        q.push({0, 1}); // 起點

        // Visited Set: 記錄已訪問的狀態 (pos, speed)
        // 使用 string key "pos_speed" 或者 set<pair<int,int>> 都可以
        // 這裡為了方便直接用 set<pair>，雖然稍微慢一點點但可讀性高
        set<pair<int, int>> visited;
        visited.insert({0, 1});

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            // 分層遍歷 (Level-order traversal)
            for (int i = 0; i < size; ++i) {
                auto [pos, speed] = q.front();
                q.pop();

                // 找到目標
                if (pos == target) return steps;

                // --- 選項 1: 執行 'A' (加速) ---
                long next_pos_A = (long)pos + speed;
                long next_speed_A = (long)speed * 2;
                
                // 剪枝 1: 不要跑太遠。
                // 如果 target 是正數，我們通常不需要跑到負數去，也不需要跑到 2倍 target 以外
                // 這是一個 heuristic 剪枝，保證搜索空間有限
                if (next_pos_A > 0 && next_pos_A < 2 * target && 
                    visited.find({(int)next_pos_A, (int)next_speed_A}) == visited.end()) {
                    
                    visited.insert({(int)next_pos_A, (int)next_speed_A});
                    q.push({(int)next_pos_A, (int)next_speed_A});
                }

                // --- 選項 2: 執行 'R' (倒車) ---
                // 只有當前進方向不對，或者已經超過目標時，倒車才有意義
                // 這裡是一個小的優化：如果我正朝著目標跑，通常不需要無緣無故 'R'
                // 但為了保證最優解的完備性，標準 BFS 還是會考慮 'R'
                
                int next_speed_R = (speed > 0) ? -1 : 1;
                // 注意 'R' 指令位置是不變的
                if (visited.find({pos, next_speed_R}) == visited.end()) {
                    visited.insert({pos, next_speed_R});
                    q.push({pos, next_speed_R});
                }
            }
            steps++;
        }
        return -1;
    }
};