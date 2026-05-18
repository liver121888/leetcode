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
        int bucketNum = (maxElement - minElement) / bucketSize + 1;  // number of buckets
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