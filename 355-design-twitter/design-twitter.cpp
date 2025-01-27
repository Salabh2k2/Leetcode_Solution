#include <vector>
#include <map>
#include <set>
#include <utility>
using namespace std;

class Twitter {
public:
    vector<pair<int, int>> tweets; // Stores (userId, tweetId) pairs
    map<int, set<int>> mp;         // Follower-followee relationship

    Twitter() {
        tweets.clear();
        mp.clear();
    }

    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        int n = tweets.size();
        int i = n - 1; // Start from the most recent tweet
        int d = 10;    // Limit to the last 10 tweets
        vector<int> ans;
        while (d > 0 && i >= 0) {
            pair<int, int> p = tweets[i];
            int user = p.first;
            if (user == userId || mp[userId].find(user) != mp[userId].end()) {
                ans.push_back(p.second);
                d--;
            }
            i--; // Move to the next older tweet
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) { // Prevent self-following
            mp[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (mp.find(followerId) != mp.end()) {
            mp[followerId].erase(followeeId); // Safely erase without checking for iterator validity
        }
    }
};
