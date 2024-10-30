// Necessary Includes Here
#ifndef REEL_H
#define REEL_H
#include "Post.h"


class Reel : public Post {


private:
	// Store video length
	int videoLength = 0;


public:
	// Constructor with parameters
	Reel(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength);


	int getVideoLength() const;
	void display();
};

#endif 
