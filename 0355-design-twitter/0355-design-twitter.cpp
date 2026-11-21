class Twitter {
public:

    int time = 0;

    // userId -> list of tweets
    unordered_map<int, vector<pair<int, int>>> tweets;

    // follower -> people they follow
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
    }

    // Post a tweet
    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time++, tweetId});
    }

    // Get latest 10 tweets
    vector<int> getNewsFeed(int userId) {

        priority_queue<
            tuple<int, int, int>
        > pq;

        // User should see their own tweets
        followMap[userId].insert(userId);

        // Get latest tweet from every followed user
        for (int followee : followMap[userId]) {

            if (!tweets.count(followee)) {
                continue;
            }

            auto &v = tweets[followee];

            int index = v.size() - 1;

            if (index >= 0) {
                pq.push({
                    v[index].first,
                    followee,
                    index
                });
            }
        }

        vector<int> ans;

        // Get maximum 10 latest tweets
        while (!pq.empty() && ans.size() < 10) {

            auto [timestamp, user, index] = pq.top();
            pq.pop();

            ans.push_back(tweets[user][index].second);

            // Add previous tweet of same user
            if (index > 0) {

                index--;

                pq.push({
                    tweets[user][index].first,
                    user,
                    index
                });
            }
        }

        return ans;
    }

    // Follow another user
    void follow(int followerId, int followeeId) {

        followMap[followerId].insert(followeeId);
    }

    // Unfollow another user
    void unfollow(int followerId, int followeeId) {

        if (followerId == followeeId) {
            return;
        }

        followMap[followerId].erase(followeeId);
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