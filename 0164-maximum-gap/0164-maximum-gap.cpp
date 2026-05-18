class Solution {
public:

    // linear time and linear space
    // we can bucket sort or more like counting sort
    // find min max of the nums
    // create buckets

    // [3,6,9,1]

    // 1 3 6 9
    // freq
    //[1 0 1 0 0 1 0 0 1]

    class Bucket {
    public:
        bool used = false;
        int minval = numeric_limits<int>::max();  // same as INT_MAX
        int maxval = numeric_limits<int>::min();  // same as INT_MIN
    };

    // k is the number of buckets
    // Time complexity: O(n+k)≈O(n), traverse nums first, then we traverse buckets that has size k
    // Space complexity: O(2⋅k)≈O(k) extra space, each bucket saves two numbers

    // 先看最佳情況：假設陣列排序後，每一對相鄰元素之間的距離都一樣。
    // 也就是說，每個相鄰元素之間都差同一個固定值。
    // 如果陣列有 n 個元素，那排序後會有 n - 1 個 gap。假設每個 gap 寬度都是 t0。
    // 那麼可以很容易得到：
    // t0 = (max - min) / (n - 1)
    // 其中 max 和 min 分別是陣列中的最大值與最小值。
    // 這個寬度就是排序後相鄰元素之間的最大 gap，也正是我們要找的東西。

    // 如果我們用 bucket 來取代個別元素作為比較單位，而且一個 bucket 可以容納多個元素，那比較次數就可以減少。
    // 因為如果我們還需要比較同一個 bucket 裡面的元素，那其實跟原本排序差不多，沒有變好。
    // 所以目前的目標是：
    // 我們希望只比較 bucket 之間，而不要比較 bucket 內部的元素。

    // 我們可以把 bucket size 設得比：
    // t0 = (max - min) / (n - 1)
    // 還要小或等於它。
    // 因為同一個 bucket 裡面的元素 gap 一定不會超過 bucket size，所以最大 gap 就一定會出現在兩個相鄰的非空 bucket 之間。
    // 因此，只要設定 bucket size b 滿足：
    // 1 < b <= (max - min) / (n - 1)
    // 就可以確保至少有一個相鄰 bucket 之間的 gap 會是答案。

    int maximumGap(vector<int>& nums) {

        // int minElement = INT_MAX/2;
        // int maxElement = INT_MIN/2;
        // for (auto num : nums) {
        //     minElement = min(minElement, num);
        //     maxElement = max(maxElement, num);
        // }        
        
        if (nums.empty() || nums.size() < 2)
            return 0;


        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());

        int bucketSize = max(1, (maxElement - minElement)/((int)nums.size() - 1));  // bucket size or capacity
        int bucketNum = (maxElement - minElement) / bucketSize + 1;  // number of buckets, remember + 1 for celiing
        vector<Bucket> buckets(bucketNum);

        for (auto num : nums) {
            int bucketIdx = (num - minElement) / bucketSize;  // locating correct bucket
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
        }

        int prevBucketMax = minElement, maxGap = 0;
        for (const auto& bucket : buckets) {
            if (!bucket.used) 
                continue;

            maxGap = max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }
        return maxGap;

        // int n = maxElement - minElement + 1;
        // 這樣開bucket 會超過memory
        // vector<int> freq(n);
        // for (auto num : nums) {
        //     freq[num - minElement] += 1;
        // }

        // int maxGap = 0;
        // int l = 0, r = 0;
        // while (r < n) {
        //     if (l != r && freq[r] > 0) {
        //         if (freq[l] == 0) {
        //             // for init
        //             l = r;
        //             continue;
        //         }
        //         maxGap = max(maxGap, r - l);
        //         // move l ptr
        //         l = r;
        //     }
        //     r++;
        // }

        // return maxGap;
    }
};