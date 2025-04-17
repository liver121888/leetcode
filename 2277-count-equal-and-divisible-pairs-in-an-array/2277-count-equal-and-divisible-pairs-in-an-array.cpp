// class Solution {
// public:

//     int combinations(int n, int k) {
//         // c n takes k
//         // eg c 3 takes 2
//         // eg c 6 takes 4
//         // 6 * 5 * 4 * 3 / 4 * 3 * 2 * 1 = 15
//         // 3 * 2 / 2 * 1 = 3
//         int top = 1;
//         int bottom = 1;
//         while (k > 0) {
//             top *= n;
//             n--;
//             bottom *= k;
//             k--;
//         }
//         return top/bottom;
//     }

//     int countPairs(vector<int>& nums, int k) {

//         // i * j / k == 0
//         // i or j at least one has to be k's multiple
//         // gen all of it?
//         // constraint is small so it's reasonable to brute-force
//         // no zero

//         // k and n is equally as big
//         // 1. come up with all k's multiple that < n
//         // 2. maintain a hash map with list, key is the number, list is the idx
//         // 3. for every pair in hash map, check the idxes, 
//         // if one of them is in k's multiple hash set, then cal the combinations
//         // time n space n

//         int n = nums.size();

//         // cout << "test: " << combinations(6, 4) << endl;
//         // cout << "test: " << combinations(3, 1) << endl;

//         unordered_set<int> multiples;
//         int i = 1;
//         while (true) {
//             int multiple = k * i;
//             if (multiple < n)
//                 multiples.insert(multiple);
//             else
//                 break;
//             i++;
//         }

//         unordered_map<int, vector<int>> num2Idx;

//         for (int i = 0; i < n; i++) {

//             if (num2Idx.find(nums[i]) == num2Idx.end()) {
//                 // new
//                 num2Idx[nums[i]] = vector<int>();
//             }
//             num2Idx[nums[i]].push_back(i);
//         }

//         // [3,1,2,2,2,1,3]
//         // 2 4 6

//         // k = 2
//         // 1 [1 5]
//         // 2 [2 3 4]
//         // 3 [0 6]
        
//         int ans = 0;
//         for (auto aPair : num2Idx) {
//             auto idxes = aPair.second;
//             int m = idxes.size();
//             for (int j = 0; j < m; j++) {
//                 cout << idxes[j] << endl;
//                 // [0 2 7 5 6]
//                 // found 2, j = 1, m = 5
//                 // ans += 4, m - j

//                 // [2 3 4]
//                 // found 2 -> should be 3-1-0 = 2
//                 // found 4 -> should be 3-1-2 = 0

//                 if (multiples.count(idxes[j])) {
//                 //     // calculate the nubmers
//                 //     int numIdx = idxes.size();
//                 //     // ans += combinations(numIdx, 2);
//                 //     break;
//                 // this idx can pair with eveything in the back and count as
//                 // valid
//                     ans += (m-1-j);
//                 }

//             }
//             cout << aPair.first << " " << ans << endl;
//         }


//         return ans;
//     }
// };


class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> num2Idx;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            num2Idx[nums[i]].push_back(i);
        }

        int ans = 0;
        for (auto& [val, idxes] : num2Idx) {
            int m = idxes.size();
            for (int i = 0; i < m; i++) {
                for (int j = i + 1; j < m; j++) {
                    if ((idxes[i] * idxes[j]) % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};