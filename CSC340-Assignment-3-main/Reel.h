#ifndef REEL_H
#define REEL_H

#include "Post.h"

class Reel :public Post {
private:
	int videoLength; //store video length

public:
	//constructor
	Reel(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength);

	int getVideoLength() const; //getter for video length
	void display() const; //display details
};

#endif 

