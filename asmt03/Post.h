// Necessary Includes Here
#ifndef POST_
#define POST_
#include <iostream>
#include <chrono>


class Post {


private:
	// Private Variables
	std::string title;
	std::chrono::time_point<std::chrono::steady_clock> time_stamp;
	int numberOfLikes;
	std::string URL;
	int videoLength;


	// This is a helper function -- it should be private.
	int computeTimeToExpiration() const;


public:
	// Default constructor, constructor with parameters, and destructor
	Post();
	Post(const std::string& title, int numberOfLikes, const std::string& URL, int videoLength);
	virtual ~Post() = default;


	//getters for the private members
	void setTitle(const std::string &title);
	std::string getTitle();
	int getNumberOfLikes() const;
	std::string getURL();
	int getVideoLength() const;
	bool isExpired();


	// Display Function
	virtual void display() const;


	// This is a function that allows you to compare two posts based on their title. 
	// You may directly include it in your class definition. 
	// You don't need to modify it but will have to put it inside your class. 
	// Operator overloading function prototype:
	bool operator==(const Post& otherPost) const;


	friend std::istream& operator>>(std::istream& in, Post& createPost);
	friend std::ostream& operator<<(std::ostream& out, Post& displayPost);
};

#endif // !POST_
