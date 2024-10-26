#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Instagram340.h"


using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type User
 * @param user object to interact with
 * 
 * */
void displayUserManu(User& user){ //gives user list of choices
	int userChoice = 0;
	do {
		cout << "\n Hi, "<< user.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Post\n"
		<< "4. Display All Posts\n"
		<< "5. Display Kth Post\n"
		<< "6. Modify Post\n"
		<< "7. Delete Post\n"
		<< "8. Edit Post\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> userChoice;

		switch (userChoice) {
			case 1:{
				// TO DO: display user's profile information
				//      : e.g. user.displayProfile();
				user.displayProfile();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update user's password
				string newPassword;
				cout << "Please enter a new password: ";
				cin >> newPassword;
				user.setPassword(newPassword);
				cout << "Password changed. \n" << endl;
				break;
			}
			case 3: {
				// TO DO: ask user to choose between Reel and Story, ask them to input post details:
				//        (title, media URL, video length in seconds)
				//        Your program should set the time stamp to current time (code provided in Post.cpp) 
				// then create the post and add it to the user's posts
				
				string choice, title, URL;
				int videoLength;
				cout << "Reel or Story: ";
				cin >> choice;
				cout << "Enter title: ";
				cin >> title;
				cout << "Enter media URL: ";
				cin >> URL;

				if (choice == "Story") {
					cout << "Max Length = 60 seconds" << endl;
					cout << "Enter video length in seconds: ";
					cin >> videoLength;
					user.createStory(title, URL, videoLength);
				}
				else if (choice == "Reel") {
					cout << "Max Length = 90 seconds" << endl;
					cout << "Enter video length in seconds: ";
					cin >> videoLength;
					user.createReel(title, URL, videoLength);
				}
				else {
					cout << "Invalid post type. \n";
				}

				break;
			}
			case 4:{
				// TO DO: display all user's posts
				//        You may re-use code from class demo
				user.displayAllPosts();
				break;
			}
			case 5: {
				// TO DO: ask the user for a value k
				// Find the Kth post, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int  index = 0;
				cout << "Enter the post index: ";
				cin >> index;
				try {
					Post* post = user.getPost(index);
					if (Story* story = dynamic_cast<Story*>(post)) {
						story->display();
					}
					else if (Reel* reel = dynamic_cast<Reel*>(post)) {
						reel->display();
					}
				}
				catch(const exception& e) {
					cout << e.what() << endl;
				}

				break;
			}
			case 6: {
				// TO DO: ask the user for the index of the post they want to modify and the new title
				// Find the post, then update the title. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag

				string choice;
				cout << "Would you like to modify a story or a reel: ";
				cin >> choice;
				int index = 0;
				string newTitle;
				cout << "Enter index of the post you want to modify: ";
				cin >> index;
				cout << "Enter new title: ";
				cin >> newTitle;

				try {
					user.modifyPostTitle(index, newTitle);
				}
				catch (exception& e) {
					cout << e.what() << endl;
				}
				if (choice == "Story") {
					cout << "You have added a filter, music, and effects to the story.";
				} else if (choice == "Reel") {
					cout << "You have added a filter, AR effects and music to the reel";
				}

				break;
			}
			case 7: {
				// TO DO: ask the user for the index of the post they want to delete 
				// Find the post, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int index = 0;
				cout << "Enter the index of the post you want to delete: ";
				cin >> index;
				try {
					user.deletePost(index);
				}
				catch (const exception& e) {
					cout << e.what() << endl;

				}
				break;
			}
			case 8: {
				//TO DO
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (userChoice != 0);
}


int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one user
	Instagram340 instagram; 

	cout << "\n Welcome to Instagram340:" << endl;
	// TO DO: Ask the user to enter their information 
	//        Instantiate a new User object

	string username, email, password, bio, profilePicture;

	cout << "Enter a username: ";
	cin >> username;
	cout << "Enter your email: ";
	cin >> email;
	cout << "Enter your password: ";
	cin >> password;
	cout << "Enter a short bio: ";
	cin >> bio;
	cout << "Choose a profile picture: ";
	cin >> profilePicture;


	// call instagram createUser function 
	// replace /*...*/ with the right parameters
	instagram.createUser(username, email, password, bio, profilePicture);

	// Retrieve the user 
	User currentUser = instagram.getUser(0);
	displayUserManu(currentUser);
				
	return 0;
}