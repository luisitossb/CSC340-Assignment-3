// Necessary Includes Here
#include <iostream>
#include <string>
#include "Instagram340.h"
#include "User.h"

// TO DO: implement constructor
Instagram340::Instagram340() : users(){

}


// Destructor
Instagram340::~Instagram340(){
	Instagram340::users.clear(); //clears the user container when Instagram340 is destroyed
}


// Greeting
std::ostream& operator<<(std::ostream& out, const Instagram340& greeting) {
	out << "Welcome to Instagram340!" << std::endl;
	return out;
}


// Create new user, add pointer to bag
void Instagram340::createUser(const std::string& username, const std::string& email, const std::string& password,
				const std::string& bio, const std::string& profilePicture){
	//create new user with parameter
	std::shared_ptr<User> newUserPtr(new User(username, email, password, bio, profilePicture));


	//adds the new user to linked bag
	users.append(newUserPtr);
}


// Get user based on index 'k'
User Instagram340::getUser(const int& indexK){
	//find user at index with 'findKthItem'
	Node<std::shared_ptr<User>>* userNode = users.findKthItem(indexK);


	// If user node not null --> call getItem() for user node
	if (userNode != nullptr) {
		return *userNode->getItem();
	}


	// If not in range of bag
	else {
		throw std::out_of_range("Invalid user index"); //throws an exception
	}
}