#include "Reel.h"
#include <iostream>
//constructor
Reel::Reel(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength) :
	Post(title, numberOfLikes, URL), videoLength(videoLength) {}

int Reel::getVideoLength() const { //getter for video length
	return videoLength;
}

void Reel::display() const { //display details
	Post::display();
	std::cout << "Video Length: " << videoLength << " seconds" << std::endl;
}