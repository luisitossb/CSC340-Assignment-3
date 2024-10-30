// Necessary Includes Here
#ifndef USER_H
#define USER_H
#include "LinkedBagDS/LinkedBag.h"
#include <string>
#include "Post.h"
#include "Story.h"
#include "Reel.h"
#include <memory>


class User {


private:
	// Private Variables
	std::string username;
	std::string email;
	std::string password;
	std::string bio;
	std::string profilePicture;
	LinkedBag<std::shared_ptr<Post>> posts;


public:
	// Default constructor, and constructor with parameters
	User();
	User(const std::string &username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);


	// Setters and Getters
	std::string getUsername() const;
	std::string getEmail() const;
	std::string getPassword() const;
	std::string getBio() const;
	std::string getProfilePicture() const;
	int getPostCount(); //get total posts
	void setPassword(const std::string& newPassword);


	void createStory(const std::string& title, const std::string& URL, int videoLength);
	void createReel(const std::string& title, const std::string& URL, int videoLength);
	void deletePost(int index);
	void displayProfile();
	void displayAllPosts() const;
	std::shared_ptr<Post> getPost(int index);
	void modifyPostTitle(int index, const std::string& newTitle);


	friend std::istream& operator>>(std::istream& in, User& userDetails);
	friend std::ostream& operator<<(std::ostream& out, const User& userProfile);


	// This is a function that allows you to compare two users based on their username and email address.
	// You may directly include it in your class definition.
	// You don't need to modify it but will have to put it inside your class.
	// Operator == overloading function prototype:
	bool operator==(const User& otherUser) const;
};

#endif
