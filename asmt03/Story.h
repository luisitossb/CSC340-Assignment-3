// Necessary Includes Here
#ifndef STORY_H
#define STORY_H
#include "Post.h"
#include <chrono>


class Story : public Post {


private:
	// Private Variables
	int videoLength = 0;
	std::chrono::time_point<std::chrono::steady_clock> expirationTime;
	const int expirationDuration = 24;


public:
	// Constructor with parameters
	Story(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength);


	bool isExpired();
	int computeTimeToExpiration() const;
	int getVideoLength() const;
	void display();
};

#endif
