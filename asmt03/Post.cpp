// Necessary Includes Here
#include <iostream>
#include <chrono>
#include "Post.h"
#include <iomanip>


// Default Constructor
Post::Post() :
	title(""),
	numberOfLikes(0),
	URL(""),
	videoLength(0){}


// Constructor with parameters
Post::Post(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength):
	title(title),
	numberOfLikes(numberOfLikes),
	URL(URL),
	videoLength(videoLength),
	time_stamp(std::chrono::steady_clock::now()) {}


// Getters and Setters
void Post::setTitle(const std::string& title) {
	this->title = title;
}
std::string Post::getTitle() {
	return title;
}
int Post::getNumberOfLikes() const {
	return numberOfLikes;
}
std::string Post::getURL() {
	return URL;
}
int Post::getVideoLength() const {
	return videoLength;
}
bool Post::isExpired() {
	return computeTimeToExpiration() <= 0;
}


// Display function
void Post::display() const {
	std::cout << "\nTitle: " << title << std::endl;
	std::time_t now = std::time(nullptr); //to print the time in human-readable language
	std::tm* localTime = std::localtime(&now);
	std::cout << "Created on: " << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
	std::cout << "\nLikes: " << numberOfLikes << std::endl;
	std::cout << "Link: " << URL << std::endl;
}


// Take in post details
std::istream& operator>>(std::istream& in, Post& postDetails) {
	std::string title, URL;
	int videoLength;
	std::cout << "Title: ";
	in >> postDetails.title;
	std::cout << "URL: ";
	in >> postDetails.URL;
	std::cout << "Video Length: ";
	in >> postDetails.videoLength;
	return in;
}


/**
std::istream& operator>>(std::istream& in, Post& createPost) {
	std::string title, Url;
	int videoLength;
	std::cout << "Enter Story title: ";
	in >> title;
	std::cout << "Enter media URL: ";
	in >> Url;
	std::cout << "Enter video length: ";
	in >> videoLength;
	return in;
}
**/

// Fix this shit, not displaying info from displayPost.title correct
// Display all posts functions still work
// take info from display user function overload
std::ostream& operator<<(std::ostream& out, Post& displayPost) {
	std::cout << "Title: " << displayPost.getTitle() << std::endl;
	std::cout << "URL: " << displayPost.getURL() << std::endl;
	std::cout << "Video Length: " << displayPost.getVideoLength() << std::endl;
	return out;
}






// DO NOT EDIT BELOW THIS LINE
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


// When creating a post, you may use this code to set time stamp
auto time_stamp = std::chrono::steady_clock::now();