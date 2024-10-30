// Necessary Includes Here
#include "Reel.h"
#include <iostream>


// Constructor with parameters
Reel::Reel(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength) :
	Post(title, numberOfLikes, URL, videoLength), videoLength(videoLength) {}


// Getter for video length
int Reel::getVideoLength() const {
	return videoLength;
}


// Display post details
void Reel::display() {
	// Call display from base class
	Post::display();
	std::cout << "Video Length: " << videoLength << " seconds" << std::endl;
}