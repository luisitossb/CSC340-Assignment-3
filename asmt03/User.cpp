// Necessary Includes Here
#include "User.h"
#include <iostream>
#include <utility>
#include "LinkedBagDS/LinkedBag.h"


// Default constructor
User::User() :
    username(""),
    email(""),
    password(""),
    bio(""),
    profilePicture("") {}


// Constructor with parameters
User::User(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture) :
    username((username)),
    email(email),
    password(password),
    bio(bio),
    profilePicture(profilePicture) {}


// Create Story
void User::createStory(const std::string& title, const std::string& URL, const int videoLength) {
    if (videoLength > 60) {
        std::cout << "Error: Story duration exceeds 60 seconds" << std::endl;
        return;
    }
    std::shared_ptr<Post> newStoryPtr(new Story(title, 0, URL, videoLength));
    posts.append(newStoryPtr);
}


// Create Reel
void User::createReel(const std::string& title, const std::string& URL, const int videoLength) {
    if (videoLength > 90) {
        std::cout << "Error: Reel duration exceeds 90 seconds" << std::endl;
        return;
    }
    std::shared_ptr<Post> newReelPtr(new Reel(title, 0, URL, videoLength));
    posts.append(newReelPtr);
}


// Getters and Setters
void User::setPassword(const std::string& newPassword) {
    password = newPassword;
}

std::string User::getPassword() const {
    return password;
}

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

int User::getPostCount() {
    return posts.getCurrentSize();
}


// Get post at specific index
std::shared_ptr<Post> User::getPost(int index) {
    auto nodePtr = posts.findKthItem(index);
    if (nodePtr != nullptr) {
        return nodePtr->getItem();
    }

    std::cout << "Out of Range, size of bag: " << getPostCount() << std::endl;
    return nullptr;
}


// Delete post at specific index
void User::deletePost(int index) {
    const std::shared_ptr<Post> post = getPost(index);
    posts.remove(post);
}


// Modify Post Title
void User::modifyPostTitle(int index, const std::string& newTitle) {
    Post *post = getPost(index).get();
    post->setTitle(newTitle);
    post->setTitle(newTitle);
}


std::istream& operator>>(std::istream& in, User& userDetails) {
    std::string username, email, password, bio, profilePicture;
    std::cout << "Username: ";
    in >> userDetails.username;
    std::cout << "Email: ";
    in >> userDetails.email;
    std::cout << "Password: ";
    in >> userDetails.password;
    std::cout << "Bio: ";
    in >> userDetails.bio;
    std::cout << "Profile Picture: ";
    in >> userDetails.profilePicture;
    return in;
}


std::ostream& operator<<(std::ostream& out, const User& userProfile) {
    out << "\nUsername: " << userProfile.username << std::endl;
    out << "Email: " << userProfile.email << std::endl;
    out << "Bio: " << userProfile.bio << std::endl;
    out << "Profile Picture: " << userProfile.profilePicture << std::endl;
    return out;
}


void User::displayAllPosts() const {
    auto postList = posts.toVector();
    for (const auto& post : postList) {
        if (auto storyPtr = std::dynamic_pointer_cast<Story>(post)) {

            // instead of storyptr - > display, we call our operator overload function instead, still do display all posts
            // But instead of display here, we use our operator overload function we're creating
            Post post;
            std::cout << post;
            // storyPtr->display();
        } else if (auto reelPtr = std::dynamic_pointer_cast<Reel>(post)) {
            // same thing here, again also for display kth post, instead of --> display, we do our operator overload function
            reelPtr->display();
        }
    }
}


// My display all posts function
// void User::displayAllPosts() const {
//     auto postList = posts.toVector();
//     for (auto& post : postList) {
//         // Using polymorphism to call the correct display method
//         post->display();
//     }
// }



// Operator == overloading implementation
bool User::operator==(const User& otherUser) const {
    return (User::username == otherUser.username) && (User::email == otherUser.email);
}
