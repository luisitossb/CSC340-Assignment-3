cmake_minimum_required(VERSION 3.29)
project(CSC340_Assignment_3_main)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(LinkedBagDS)

add_executable(CSC340_Assignment_3_main
    Instagram340.cpp
    Instagram340.h
    InstagramMain.cpp
    Post.cpp
    Post.h
    Reel.cpp
    Reel.h
    Story.cpp
    Story.h
    User.cpp
    User.h)
