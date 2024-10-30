// Necessary Includes Here
#ifndef INSTAGRAM340_H
#define INSTAGRAM340_H
#include "LinkedBagDS/LinkedBag.h"
#include "User.h"
#include <string>
#include <memory>


// This class only contains a list of users
// It should allow clients to add users and retrieve a user from the list
class Instagram340 {
	private:
		// Initialize Linked Bag with users
		LinkedBag<std::shared_ptr<User>> users;


	public:
		// Constructor and Destructor respectively
		Instagram340();
		~Instagram340();


		// Greeting Friend function
		friend std::ostream& operator<<(std::ostream& out, const Instagram340& greeting);


		// Create User with Parameters
		void createUser(const std::string& username, const std::string& email, const std::string& password,
						const std::string& bio, const std::string& profilePicture);


		// Get user based on index 'k'
		User getUser(const int& indexK);


};

#endif