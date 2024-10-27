#include "Story.h"
#include <iostream>
#include <chrono>
//constructor
Story::Story(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength) :
	Post(title, numberOfLikes, URL) {
	expirationTime = std::chrono::steady_clock::now() + std::chrono::hours(expirationDuration);
}

bool Story::isExpired() { //check if story is expired
	return std::chrono::steady_clock::now() >= expirationTime;
}

int Story::computeTimeToExpiration() const {
	auto now = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::hours>(expirationTime - now);
	return duration.count() / 3600;
}

void Story::display() { //display details of the post
	Post::display(); //call the display from base class

	if (isExpired()) { //check is story is expired
		std::cout << "This story is expired." << std::endl;
	}
	else {
		std::cout << "Time to expiration: " << computeTimeToExpiration() << " hours" << std::endl;
	}
}