// TO DO: #include all the standard libraries and your own libraries here
#include <iostream>
#include <chrono>
#include "Post.h"

#include <iomanip>


// TO DO: function implementations

Post::Post(const std::string& title, int numberOfLikes, const std::string& URL) :
	title(title),
	numberOfLikes(numberOfLikes),
	URL(URL),
	time_stamp(std::chrono::steady_clock::now()) {}

std::string Post::getTitle() { //getter for title
	return title;
}

void Post::setTitle(const std::string& title) { //setter for title
	this->title = title;
}

// When creating a post, you may use this code to set time stamp
auto time_stamp = std::chrono::steady_clock::now();

int Post::getNumberOfLikes() const { //getter for number of likes
	return numberOfLikes;
}

std::string Post::getURL() { //getter for URL
	return URL;
}

bool Post::isExpired() const { //checking if the post is expired
	return computeTimeToExpiration() <= 0;
}

void Post::display() const { //displaying the posts
	std::cout << "\nTitle: " << title << std::endl;
	std::time_t now = std::time(nullptr); //to print the time in human-readable language
	std::tm* localTime = std::localtime(&now);
	std::cout << "Created on: " << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
	std::cout << "\nLikes: " << numberOfLikes << std::endl;
	std::cout << "Link: " << URL << std::endl;

}

// ------------------------------------------------------------------------------
// Operator overloading implementation
bool Post::operator==(const Post& otherPost) const {
	return Post::title == otherPost.title;
}

// When displaying a story, use this to compute expected expiration time: timeToExpiration
// Define this as a private function
int Post::computeTimeToExpiration() const{
	const int secondsInHour = 3600;
	// 24 hours in seconds
	const int expiresAfter = 24 * secondsInHour;

	// Get current time
	auto time_now = std::chrono::steady_clock::now();
	// Compute elapsed time since post creation
	std::chrono::duration<double> elapsed_seconds = time_now - Post::time_stamp;
	// time to expiration in hours
	int timeToExpiration = (expiresAfter - elapsed_seconds.count()) / secondsInHour;

	return timeToExpiration;
}


