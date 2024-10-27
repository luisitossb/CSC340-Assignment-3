// TO DO: #include all the standard libraries and your own libraries here
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
//store user info
	std::string username;
	std::string email;
	std::string password;
	std::string bio;
	std::string profilePicture;
	LinkedBag<std::shared_ptr<Post>> posts;

public:
	User(); //default constructor
	//constructor
	User(const std::string &username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);
	//getters to retrieve info
	std::string getUsername() const;
	std::string getEmail() const;
	std::string getBio() const;
	std::string getProfilePicture() const;
	//display profile
	void displayProfile();
	void setPassword(const std::string& newPassword); //set new password
	//functions for creating posts
	void createStory(const std::string& title, const std::string& URL, int videoLength);
	void createReel(const std::string& title, const std::string& URL, int videoLength);
	void displayAllPosts() const; //display all posts
	std::shared_ptr<Post> getPost(int index); //get a specific post
	void modifyPostTitle(int index, const std::string& newTitle); //change post title
	void deletePost(int index); //delete a post

	int getPostCount(); //get total posts


	// To DO: define the class User with the necessary functions and data fields

	// This is a function that allows you to compare two users based on their username and email address.  
	// You may directly include it in your class definition. 
	// You don't need to modify it but will have to put it inside your class. 
	// Operator == overloading function prototype:
	bool operator==(const User& otherUser) const;
};
#endif