class Twitter {
public:
    unordered_map<int,set<int>> followMap; // u1 : {u2,u3,u4}
    unordered_map<int,vector<pair<int,int>>> tweetMap; // u1 : {1,t1} {2,t2}
    int tweetCnt; // shared var for all users 
    Twitter() {
        tweetCnt = 0; // shared var for all users 
    }
    
    void postTweet(int userId, int tweetId) {
        tweetCnt++;
        tweetMap[userId].push_back({tweetCnt,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int> followersId = followMap[userId]; // u2,u3 etc
        cout << followersId.size() << endl;
        // add user also 
        followersId.insert(userId);
        // iterate tweets from followersId = u2,u3 etc && userId
        // store what your queries read, not what your domain has

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> top10Tweets;

        for(int follower: followersId){ // iterate the map
            vector<pair<int,int>> tweets = tweetMap[follower];
            for(auto tweet: tweets){
                if(top10Tweets.size()<10){
                    top10Tweets.push(tweet);
                }else if(top10Tweets.top().first<tweet.first){
                    top10Tweets.pop();
                    top10Tweets.push(tweet);
                }
            }
        }

        vector<int> result;
        while(!top10Tweets.empty()){
            result.push_back(top10Tweets.top().second);
            top10Tweets.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        // map : userId, vector<string> userId, push into this (o(1))
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // map : userId, vector<string> userId, remove into this (o(n))
        followMap[followerId].erase(followeeId);
    }
};
