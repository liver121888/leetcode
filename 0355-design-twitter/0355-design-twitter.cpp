class Twitter {
public:

    // tweetId -> userId
    // userId -> multiple userID that is the 10 most recent tweets in that user's feed
    // users who the user followed or by the user themselves
    // Tweets must be ordered from most recent to least recent.
    // tweetId is not an increasing order

    // this user post there tweets
    // front-> most recent 
    // userId -> queue<tweetId>

    // tweetId -> timestamp

    // follows -> vector<unordered_set<int>>

    // 0 -> 0 2 4
    // 1 -> 5 6 7  

    // if 0 follows 1
    // need to mrge multiple sorted list

    // postTweet
    // O(1)
    // if no userId -> create that
    // follow the user himself
    // push to userId's queue
    // tweetId -> timestamp
    // increase timecnt

    // O(1)
    // follow -> insert in the set
    // unfollow -> remvoe from set

    // getNewsFeed
    // get the ones that the user follows
    // get the list of queue of tweetid
    // priority_queue keep a min(10)
    // O(n log 10)

    // userId -> user's posts
    unordered_map<int, queue<int>> userTweets;
    // tweetId -> timestamp
    unordered_map<int, int> tweetTime;
    // follows -> vector<unordered_set<int>>
    unordered_map<int, unordered_set<int>> follows;

    int t = 0;
    int postLimit = 10;

    Twitter() {
        
    }

    void createUser(int userId) {
        userTweets[userId] = queue<int>();
        follows[userId] = unordered_set<int>();
        follows[userId].insert(userId);
    }
    
    void postTweet(int userId, int tweetId) {

        if (userTweets.find(userId) == userTweets.end())
            createUser(userId);

        auto& postQueue = userTweets.at(userId);
        postQueue.push(tweetId);

        if (userTweets.at(userId).size() > postLimit)
            postQueue.pop();

        tweetTime[tweetId] = t;
        t++;        
    }
    
    vector<int> getNewsFeed(int userId) {

        // if there is no feed
        if (follows.find(userId) == follows.end())
            return {};

        const auto& following = follows.at(userId);

        // larger timestamp -> recent
        // so we want a minheap, 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        for (const auto& id : following) {
            
            // user has not post yet
            if (userTweets.find(id) == userTweets.end())
                continue;

            queue<int> q = userTweets[id];
            while (!q.empty()) {
                const auto id = q.front();
                q.pop();
                pq.push({tweetTime[id], id});
                if (pq.size() > postLimit)
                    pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            const auto [_, id] = pq.top();
            ans.push_back(id);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (follows.find(followerId) == follows.end())
            createUser(followerId);

        if (follows.find(followeeId) == follows.end())
            createUser(followeeId);
        

        follows[followerId].insert(followeeId);

    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */