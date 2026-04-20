
// can only do simulation because
// 狀態具有「連鎖反應」與「即時更新」特性這題最關鍵的地方在於：
// 每一滴水落下的位置，都會立即改變地貌，進而影響下一滴水的路徑。
// 如果你嘗試用「直接求解」（例如計算區間面積或雙指針），你會發現地面的形狀是不斷變動的動態系統。
// 直接求解通常適用於「靜態場景」或是「最終穩定態可以用數學公式描述」的情況。
// 但在這裡，水滴的路徑依賴於前一刻的精確高度差。
// 2. 局部最優解不等於全域最優解觀察題目規則：水滴會停在往該方向走能遇到的「最後一個窪地」。
// 這代表：水滴不是填滿整個大坑，而是尋找路徑上第一個能掉進去的坑。
// 如果使用數學計算（如：計算 $K$ 左右兩側的容積），你很難處理「水滴被一個小凸起擋住」的情況。
// 模擬法則能自然地處理這種「擋路」的邏輯。
// 3. 規則中存在明確的優先順序題目給出了非常明確的「動作順序」：優先向左尋找最低點。
// 若無，則向右尋找最低點。若皆無，則原地。這種 「If A fails, try B, then C」 
// 的結構是典型的狀態機模擬特徵。

#include <vector>

class Solution {
public:
    std::vector<int>& pourWater(std::vector<int>& H, int V, int K) {
        while (V-- > 0) {
            bool placed = false;
            // d = -1 是向左，d = 1 是向右
            for (int d : {-1, 1}) {
                int i = K, best = K;
                // 只要下一個位置在範圍內且高度不大於當前位置，水滴就能繼續滾動
                while (i + d >= 0 && i + d < H.size() && H[i + d] <= H[i]) {
                    if (H[i + d] < H[i]) {
                        best = i + d; // 紀錄遇到的最低點
                    }
                    i += d;
                }
                
                // 如果找到比 K 更低的位置，就填入並處理下一滴
                if (H[best] < H[K]) {
                    H[best]++;
                    placed = true;
                    break; 
                }
            }
            
            // 如果左右都流不去，就留在原點 K
            if (!placed) {
                H[K]++;
            }
        }
        return H;
    }
};

// Input: heights = [2,1,1,2,1,2,2], volume = 4, k = 3
// Output: [2,2,2,3,2,2,2]
// the water stops flowing when the 
// currHeight + self is not > than the side

// Example 2:
// Input: heights = [1,2,3,4], volume = 2, k = 2
// Output: [2,3,3,4]
// Explanation: The last droplet settles at index 1, 
// since moving further left would not cause it to eventually fall to a lower height.

// Example 3:
// Input: heights = [3,1,3], volume = 5, k = 1
// Output: [4,4,4]

// so when a water drops on a index, it has to fill every cell on its
// left or right to the same height as current
// will there be some situation is that it can flow both way?

// eg. [211111111111 1 11111111111 2], 5
// which side should it goes first?
// it should goes to left first but then quickly right, so should be center
// [21111111 11 22 2 22 111111111 2]

// from the index
// we go to left first to see anything that's lower
// fill the up
// if stil some volume left, fill the right

// "eventually fall" means that the droplet will eventually be at a
//  lower level if it moves in that direction. Also, level means the 
//  height of the terrain plus any water in that column.

// we can start at the index
// three pointers
// heights[k]
// heights[l]
// heights[r]


// Input: heights = [2,1,1,2,1,2,2], volume = 4, k = 3
// l 1
// k 2 
// r 1

// if l < k -> flow to l and fill to height[k+1]
// cannot fill
// check bound 
// if r < k -> flow to r
// check bound 

// think of moving two infinite wallto the side
// inittially it has volume water
// l 1
// k 2 
// r 1
// we move the left wall and create (2 - 1)*1, volume - 1
// l 2
// k 2 
// r 1
// we move the right wall and create (2 - 1)*1, volume - 1
// we move the left wall and create (2 - 1)*1, volume - 1
// l 2
// if cannot move boundary, just place the rest of the water in the middle


// class Solution {
// public:
//     vector<int> pourWater(vector<int>& heights, int volume, int k) {

//         if (n == 1) {
//             heights[0] += volume;
//             return heights;
//         }

//         int n = heights.size();
//         int l = k-1, r = k+1;

//         while (volume > 0) {

//             if (l >= 0) {
//                 if (heights[l] < heights[k]) {

//                 }

//             }

//             if (r < n) {

//             }



//         }

//         return heights;

//     }
// };