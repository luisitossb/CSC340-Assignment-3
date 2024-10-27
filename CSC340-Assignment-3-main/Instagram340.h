#ifndef INSTAGRAM340_H
#define INSTAGRAM340_H
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"
#include <string>
#include <memory>

// TO DO include necessary libraries

 

// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340 {
	private:
		LinkedBag<std::shared_ptr<User>> users;

	public:
		Instagram340(); //constructor
		~Instagram340(); //destructor
		//create a new user with parameters
		void createUser(const std::string& username, const std::string& email, const std::string& password,
						const std::string& bio, const std::string& profilePicture);
		//retrieve user given index
		User getUser(const int& indexK);
};

#endif