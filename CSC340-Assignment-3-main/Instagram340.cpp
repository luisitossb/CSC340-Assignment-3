// TO DO: Implementation of Instagram340 functions
#include <iostream>
#include <string>
#include "Instagram340.h"
#include "User.h"

Instagram340::Instagram340() : users(){
	// TO DO: implement constructor
}

Instagram340::~Instagram340(){ //destructor
	Instagram340::users.clear(); //clears the user container when Instagram340 is destroyed
}
//create a new user
void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
	// TO DO: implement function
	//create new user with parameters
	std::shared_ptr<User> newUserPtr(new User(username, email, password, bio, profilePicture));
	//adds the new user to linked bag
	users.append(newUserPtr);
}
//retrieve user based on index
User Instagram340::getUser(const int& indexK){
	// TO DO: implement function
	//find user at index
	Node<std::shared_ptr<User>>* userNode = users.findKthItem(indexK);
	
	if (userNode != nullptr) { //check if userNode is not null
		return *userNode->getItem(); //return user in the node
	}
	else {
		throw std::out_of_range("Invalid user index"); //throws an exception
	}
}