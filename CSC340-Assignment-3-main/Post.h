// TO DO: #include all the standard libraries and your own libraries here
#ifndef POST_
#define POST_

#include <iostream>
#include <chrono>


// To DO: define the class Post with the necessary functions' prototypes and data fields

class Post {

private:
	std::string title; //title of post
	std::chrono::time_point<std::chrono::steady_clock> time_stamp; //time stamp of post
	int numberOfLikes; //number of likes that a post has
	std::string URL; //URL to the media

	// This is a helper function -- it should be private.
	int computeTimeToExpiration() const;

public:
	//constructor
	Post(const std::string& title, int numberOfLikes, const std::string& URL);

	virtual ~Post() = default;

	//getters for the private members
	std::string getTitle();

	void setTitle(const std::string &title);

	int getNumberOfLikes() const;

	std::string getURL();

	bool isExpired() const;

	// This is a function that allows you to compare two posts based on their title. 
	// You may directly include it in your class definition. 
	// You don't need to modify it but will have to put it inside your class. 
	// Operator overloading function prototype:
	bool operator==(const Post& otherPost) const;

	virtual void display() const; //display the post

};
#endif // !POST_
