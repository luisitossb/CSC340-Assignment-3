// Necessary Includes Here
#include <iostream>
#include <string>
#include <algorithm>
#include "Instagram340.h"
using namespace std;


// Display User Menu
void displayUserManu(User& user){
	// Basic interface
	int userChoice = 0;
	do {
		cout << "\nHi, "<< user.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Post\n"
		<< "4. Display All Posts\n"
		<< "5. Display Kth Post\n"
		<< "6. Modify Post\n"
		<< "7. Delete Post\n"
		<< "8. Edit Post\n"
		<< "0. Logout\n"
		<< "Choice:";
		cin >> userChoice;


		// Switch statement for taking in user options and carrying out functions
		switch (userChoice) {
			// Display User (finished)
			case 1:{
				cout << user;


				break;
			}

			// Change password (need to make it work with our new user object)
			case 2: {
				// Takes in new user password, then calls setPassword
				string newPassword;
				cout << "Please enter a new password: ";
				cin >> newPassword;
				user.setPassword(newPassword);
				cout << "Password changed. \n" << endl;


				break;
			}

			// Create Reel or Story
			case 3: {
				// Takes in user choice of Reel or Story
				string choice;
				cout << "Reel or Story: ";
				cin >> choice;
				std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower); // Ignore case


				// Create Post object with info for Reel or Story
				Post createPost;
				cin >> createPost;


				// Calls createStory or createReel based on user choice
				if (choice == "story") {
					user.createStory(createPost.getTitle(), createPost.getURL(), createPost.getVideoLength());
				}
				else if (choice == "reel") {
					user.createReel(createPost.getTitle(), createPost.getURL(), createPost.getVideoLength());
				}
				else {
					cout << "Invalid post type. \n";
				}


				break;
			}


			// Display ALL user posts
			case 4:{
				user.displayAllPosts();

				// correct this, not displaying any info
				// Understands that there is multiple DIFFERENT posts though, just not retrieving info
				// Post displayPost;
				// cout << displayPost;


				break;
			}


			// Display post at specific index
			case 5: {
				// Takes user index
				int index;
				cout << "Enter post index: ";
				cin >> index;
				// If invalid input
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid number.\n";
				}


				// Get post at specific index w/ pointer
				std::shared_ptr<Post> post = user.getPost(index);


				// Display method called
				post->display();


				break;
			}


			// Modify Post at specific index
			case 6: {
				// Asks to modify Story or Reel
				string choice;
				cout << "Would you like to modify a story or a reel: ";
				cin >> choice;
				std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower); // Ignore case


				// Get specific index
				int index = 0;
				string newTitle;
				cout << "Enter index of the post you want to modify: ";
				cin >> index;
				// If invalid input
				if (cin.fail()) {
					cin.clear(); // Clear the fail state
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid number.\n";

				}


				// Changes title
				cout << "Enter new title: ";
				cin >> newTitle;
				user.modifyPostTitle(index, newTitle);


				break;
			}


			// Delete post at specific index
			case 7: {
				// Get specific index
				int index = 0;
				cout << "Enter the index of the post you want to delete: ";
				cin >> index;
				// If invalid input
				if (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a valid number.\n";
				}


				// Delete post with exception handling
				try {
					user.deletePost(index);
				}
				catch (const exception& e) {
					cout << e.what() << endl;

				}


				break;
			}


			// Modify post or reel
			case 8: {
				// Ask for story or reel to modify
				string choice;
				cout << "Do you want to modify a story or a reel: ";
				cin >> choice;
				std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower); // Ignore case


				// If edited story, reel, or something else
				if (choice == "story") {
					cout << "Filter, music, and effects were added to your Story.";
				}
				else if (choice == "reel") {
					cout << "Filter, AR effects, and music were added to your Reel.";
				}
				else {
					cout << "Unknown choice, but the title has been modified successfully.";
				}


				break;
			}


			// Fix this, so it doesn't say this when we give it a string, still works for 0 though
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}


			// Doesn't work, never see it unless we give it a large number, doesn't work for string
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (userChoice != 0);
}


// MAIN XD
int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user (Want to edit to have multiple users)
	Instagram340 instagram;


	// Greeting at beginning --> "Welcome to Instagram340"
	Instagram340 greeting;
	cout << greeting;


	// Take user details input
	cout << "[Please provide the following information]" << endl;
	User userDetails;
	cin >> userDetails;


	// Create user
	instagram.createUser(userDetails.getUsername(),
		userDetails.getEmail(),
		userDetails.getPassword(),
		userDetails.getBio(),
		userDetails.getProfilePicture());


	// Retrieve the user
	User currentUser = instagram.getUser(0);
	displayUserManu(currentUser);


	// End Program
	return 0;
}