#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>

class Twitter {
public:
	/** Initialize your data structure here. */
	Twitter() : mTweetSeq{ 0 } {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		mTweetData[userId].push_back({ mTweetSeq++, tweetId });
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	std::vector<int> getNewsFeed(int userId) {

		std::vector<int> ret;
		std::vector<std::pair<Tweet*, Tweet*>> tweets;

		auto& myTweets = mTweetData[userId];
		if (myTweets.size())
		{
			tweets.push_back({ myTweets.data(), myTweets.data() + myTweets.size() - 1 });
		}

		for (auto const& user : mRelation[userId])
		{
			auto& followeeTweets = mTweetData[user];
			if (followeeTweets.size())
			{
				tweets.push_back({ followeeTweets.data(), followeeTweets.data() + followeeTweets.size() - 1 });
			}
		}

		auto lambda = [](std::pair<Tweet*, Tweet*> const& a, std::pair<Tweet*, Tweet*> const& b) {
			return a.second->mTweetSeq < b.second->mTweetSeq;
		};

		std::make_heap(tweets.begin(), tweets.end(), lambda);
		for (int i = 0; i < 10 && !tweets.empty(); i++)
		{
			std::pop_heap(tweets.begin(), tweets.end(), lambda);
			std::pair<Tweet*, Tweet*>& top = tweets.back();
			ret.push_back(tweets.back().second->mTweetId);

			if (top.first == top.second--)
			{
				tweets.pop_back();
			}
			else
			{
				std::push_heap(tweets.begin(), tweets.end(), lambda);
			}
		}

		return ret;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		if (followerId != followeeId && mRelation[followerId].find(followeeId) == mRelation[followerId].end())
		{
			mRelation[followerId].insert(followeeId);
		}
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		if (mRelation.find(followerId) != mRelation.end())
		{
			mRelation[followerId].erase(followeeId);
		}
	}
private:
	struct Tweet
	{
		Tweet(int tweetSeq, int tweetId) : mTweetSeq{ tweetSeq }, mTweetId{ tweetId } {}
		int mTweetSeq;
		int mTweetId;
	};
private:
	int mTweetSeq;
	std::unordered_map<int, std::set<int>> mRelation;
	std::unordered_map<int, std::vector<Tweet>> mTweetData;
};
