cmake_minimum_required(VERSION 3.29)
project(asmt03)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(asmt03
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
