// Necessary Includes Here
#include "Story.h"
#include <iostream>
#include <chrono>


// Constructor with parameters
Story::Story(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength) :
	Post(title, numberOfLikes, URL, videoLength), videoLength(videoLength) {
	expirationTime = std::chrono::steady_clock::now() + std::chrono::hours(expirationDuration);
}


// Return if story is expired
bool Story::isExpired() {
	return std::chrono::steady_clock::now() <= expirationTime;
}


int Story::computeTimeToExpiration() const {
	auto now = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::hours>(expirationTime - now);
	return duration.count() / 3600;
}


// Display post details
void Story::display(){
	// Call display from base class
	Post::display();


	// Check if story is expired
	if (isExpired()) {
		std::cout << "This story is expired." << std::endl;
	}
	else {
		std::cout << "Time to expiration: " << computeTimeToExpiration() << " hours" << std::endl;
	}
}
