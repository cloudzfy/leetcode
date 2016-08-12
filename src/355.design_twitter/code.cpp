struct cmp {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

class Twitter {
private:
    unordered_map<int, vector<pair<int, int> > > tweets;
    unordered_map<int, unordered_set<int> > followers;
    int nowtime;
public:
    /** Initialize your data structure here. */
    Twitter() {
        nowtime = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(tweetId, nowtime++));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        set<pair<int, int>, cmp> s;
        for (int i = 0; i < tweets[userId].size(); i++) {
            s.insert(tweets[userId][i]);
        }
        for (auto it = followers[userId].begin(); it != followers[userId].end(); it++) {
            for (int j = 0; j < tweets[*it].size(); j++) {
                s.insert(tweets[*it][j]);
            }
        }
        vector<int> feeds;
        auto it = s.begin();
        for (int i = 0; i < 10 && it != s.end(); i++) {
            feeds.push_back(it->first);
            it++;
        }
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto it = followers[followerId].find(followeeId);
        if (it != followers[followerId].end()) {
            followers[followerId].erase(it);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
