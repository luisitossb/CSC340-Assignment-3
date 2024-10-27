#ifndef STROY_H
#define STORY_H

#include "Post.h"
#include <chrono>

class Story : public Post {
private:
	std::chrono::time_point<std::chrono::steady_clock> expirationTime; //time point to track when story expires
	const int expirationDuration = 24; //duration for when story remains active 24 hours

public:
	//constructor
	Story(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength);

	bool isExpired(); //check if story is expired
	int computeTimeToExpiration() const; //compute hours remaining until story expires

	void display(); //display details
};


#endif

