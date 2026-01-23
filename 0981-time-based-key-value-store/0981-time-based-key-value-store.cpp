
// for a single key, we might have multiple values
// we return the value that has a timestamp <= query_timestamp

// we can use an unordered_map
// {string, vector{string}}
// we also need a string -> time data structure
// strictly increasing -> unique value
// so we can use time value to link to string


// unordered_map<string, vector<pair<int,int>> {timestamp, value}>

// n query
// time:
// construct: O(1)
// set: we can do find then insert (n*log(n)) or simply sort, it's the same
// get: O(log(n)), we simply search
// space: O(n)

class TimeMap {
public:

    unordered_map<string, vector<pair<int,string>>> timeMap;

    TimeMap() {

        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
        // we don't need sorting because it's strictly increasing
        
    }
    
    string get(string key, int timestamp) {
        // 1. 檢查 Key 是否存在
        if (timeMap.find(key) == timeMap.end()) {
            return "";
        }

        // 加上引用 &，避免複製 vector (非常重要！)
        const vector<pair<int,string>>& values = timeMap[key];

        // 2. 如果所有的 timestamp 都比 target 大，直接回傳空
        if (values[0].first > timestamp) {
            return "";
        }

        // 萬用模板開始
        // find uppper bound, right boundary
        int l = 0;
        int r = values.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (values[mid].first <= timestamp) {
                l = mid + 1; // 我們要找更大的，往右邊縮
            } 
            else {
                r = mid - 1; // 目前的太大了，往左邊縮
            }
        }

        // 迴圈結束後：
        // l 會在「第一個大於 target」的位置
        // r 會在「最後一個小於 target」的位置 (這就是我們要的 <= 條件)
        
        return values[r].second; 
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */