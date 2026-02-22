// nums = [1,2,3,3,4,4,5,6], k = 4

// [3,2,1,2,3,4,3,4,5,9,10,11], k = 3

// nums = [1,2,3,4], k = 3
// size = 4, 4 % 3 != 0, we can return false early

// we cannout use the elements twice

// k will at least be 1, nums.size()
// all positive numbers
// yes

// sort the array and check consecuitive
// O(nlogn)

// count freq of the elements
// nums = [1,2,3,3,4,4,5,6], k = 4
// 1,1 2,1 3,2, 4,2, 5,1, 6,1
// 1,0 2,0 3,1, 4,1, 5,1, 6,1
// [1,2,3,3,4,5,5,6], k=4
// 1,0 2,0 3,1, 4,0, 5,2, 6,1
// unoreder_map, vector for all the keys, index of the current 
// time: O(n)
// space: O(n)

// we build the unoreder_map, and the vector
// init vectorIdx = 0
// if the key exist in unordered_map and the value is not 0
// for (i in range vectorIdx : vectorIdx+k)
// if the key does not exist
// we return false
// if k of them exist
// we deduct by min(4 values) in the value
// if the key exist in unordered_map and the value is already 0
// we increase vectorIdx and coninue;

// vector check for consecuitive
// we take keys[0] is 1 here
// we check if keys[1], ... keys[0+k] is 1 + 1, .. 1 +k
// if not we know return false
// the values we took out we take the min, all of them shoud not be 0
// if there is 0, we return false
// we remove the min from the values
// we take keys[1]
// if it's not 0, we do the thing again

// O(nlogn) for sorting the key
// O(n) for storing the keys and the map

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if (nums.size() % k != 0)
            return false;

        unordered_map<int,int> freq;

        for (auto num : nums) {
            freq[num]++;
        }

        vector<int> keys;
        for (auto f : freq) {
            keys.push_back(f.first);
        }

        sort(keys.begin(), keys.end()); 

        for (int keyIdx = 0; keyIdx < keys.size(); keyIdx++) {
            int startKey = keys[keyIdx];
            if (freq.find(startKey) == freq.end())
                continue;
            int minValue = INT_MAX;
            for (int i = startKey; i < startKey + k; i++) {
                if (freq.find(i) == freq.end())
                    return false;
                minValue = min(minValue, freq[i]);
            }
            for (int i = startKey; i < startKey + k; i++) {
                freq[i] -= minValue;
                if (freq[i] == 0)
                    freq.erase(i);
            }
        }

        return freq.size() == 0;
        
    }
};