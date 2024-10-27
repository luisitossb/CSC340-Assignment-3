// TO DO: #include needed standard libraries and your own libraries here
#include "User.h"
#include <iostream>
#include <utility>
#include "LinkedBagDS/LinkedBag.h"

// TO DO: function implementations

//constructors
User::User() : //default constructor
    username(""),
    email(""),
    password(""),
    bio(""),
    profilePicture("") {}
//constructor
User::User(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture) :
    username((username)),
    email(email),
    password(password),
    bio(bio),
    profilePicture(profilePicture) {}
//create a story
void User::createStory(const std::string& title, const std::string& URL, const int videoLength) {
    if (videoLength > 60) {
        std::cout << "Error: Story duration exceeds 60 seconds" << std::endl;
        return;
    }
    std::shared_ptr<Post> newStoryPtr(new Story(title, 0, URL, videoLength));
    posts.append(newStoryPtr);
}
//create a reel
void User::createReel(const std::string& title, const std::string& URL, const int videoLength) {
    if (videoLength > 90) {
        std::cout << "Error: Reel duration exceeds 90 seconds" << std::endl;
        return;
    }
    std::shared_ptr<Post> newReelPtr(new Reel(title, 0, URL, videoLength));
    posts.append(newReelPtr);
}
//set new password for user
void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

//getters
std::string User::getUsername() const {
    return username;
}

std::string User::getEmail() const {
    return email;
}

std::string User::getBio() const {
    return bio;
}

std::string User::getProfilePicture() const {
    return profilePicture;
}
//display details of user
void User::displayProfile() {
    std::cout << "Username: " << username << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Bio: " << bio << std::endl;
    std::cout << "Profile Picture: " << profilePicture << std::endl;
}
//display all the posts
// displays all users posts
void User::displayAllPosts() const {
    auto postList = posts.toVector();
    for (const auto& post : postList) {
        if (auto storyPtr = std::dynamic_pointer_cast<Story>(post)) {
            storyPtr->display();
        } else if (auto reelPtr = std::dynamic_pointer_cast<Reel>(post)) {
            reelPtr->display();
        }
    }
}
//get a specific post
std::shared_ptr<Post> User::getPost(int index) {
    auto nodePtr = posts.findKthItem(index); //find post at given index
    if (nodePtr != nullptr) {
        return nodePtr->getItem(); //return the post found
    }

    std::cout << "Out of Range, size of bag: " << getPostCount() << std::endl; //throwing exception error
    return nullptr; //returns null pointer if index is invalid
}
//modify the post title
void User::modifyPostTitle(int index, const std::string& newTitle) {
    Post *post = getPost(index).get();
    post->setTitle(newTitle);
    post->setTitle(newTitle);
}
//delete a post given index
void User::deletePost(int index) {
    const std::shared_ptr<Post> post = getPost(index);
    posts.remove(post);
    //delete post;
}
//get count of how many post
int User::getPostCount() {
    return posts.getCurrentSize();
}
// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
    return (User::username == otherUser.username) && (User::email == otherUser.email);
}