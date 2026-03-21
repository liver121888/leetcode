
// All the timestamps timestamp of set are strictly increasing.
// unordered_map<key, vector<pair<int, value>>> 
// because the call is strictly increasing
// but we might also want to find a value that is <=
// we can have a vector and we binary search
// time for set: O(1)
// time for get: O(log(n))

class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> timeMap;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {

        timeMap[key].emplace_back(timestamp, value);
        
    }

    // timestamp_prev <= timestamp not larger than the target
    // 3 4 5 6 7 10
    // l = 3, r = 10
    // 5 < 7
    // l = 5
    // 6
    // 6 < 7
    // l = 6
    // l = 10, r = 10
    // r 6
    // return r
    int findLastLE(const vector<pair<int, string>>& v, int target) {

        int l = 0, r = v.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (v[mid].first <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
    
    string get(string key, int timestamp) {

        if (timeMap.find(key) == timeMap.end())
            return "";
        
        const vector<pair<int, string>>& timeValues = timeMap[key];
        int idx = findLastLE(timeValues, timestamp);
        return idx == -1 ? "" : timeValues[idx].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */