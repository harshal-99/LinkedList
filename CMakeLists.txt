cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

project(LinkedList)

find_package(Catch2 REQUIRED)


add_executable(LinkedListTest
		src/mainTest.cpp src/LinkedList.cpp
		include/LinkedList.hpp src/test.cpp)

target_link_libraries(LinkedListTest Catch2::Catch2)

add_executable(LinkedList
		src/LinkedList.cpp
		include/LinkedList.hpp
		src/main.cpp src/main.cpp)