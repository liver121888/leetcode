class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        // Step 1：排序（關鍵！）
        // 先按照 startTime 排序
        int n = startTime.size();

        vector<tuple<int,int,int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.emplace_back(startTime[i], endTime[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end());

        // create start time array so we can find next available job quickly
        vector<int> starts;
        for (const auto& [s,e,p] : jobs) {
            starts.push_back(s);
        }

        // Step 2：定義 DP
        // dp[i] = 從第 i 個 job 開始能拿到的最大 profit
        // 所以從尾巴走到0
        vector<int> dp(n + 1, 0);

    
        // Step 3：轉移（最核心）
        // 對於每個 job i：
        // 你有兩個選擇：
        // 1️⃣ 不選這個 job
        // 2️⃣ 選這個 job
        // 你要找：
        // 👉 下一個 start >= end[i] 的 job
        // 用 binary search 找到 index j
        for (int i = n - 1; i >= 0; i--) {
            const auto& [s, e, p] = jobs[i];
            // find >= end, j is the index
            int j = lower_bound(starts.begin(), starts.end(), e) - starts.begin();

            dp[i] = max(dp[i+1], p + dp[j]);
        }
        return dp[0];
    
    }
};