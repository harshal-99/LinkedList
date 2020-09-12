#include "../include/LinkedList.hpp"
#include <catch2/catch.hpp>

TEST_CASE("LinkedList") {
	LinkedList list(1);

	SECTION("push_back") {
		list.push_back(2);
		auto l = list.traverse(0);
		REQUIRE(l->val == 1);
		l = list.traverse(99);
		REQUIRE(l->val == 2);
		list.push_back(3);
		l = list.traverse(99);
		REQUIRE(l->val == 3);
		list.push_back(4);
		list.push_back(5);
	}
//	SECTION("Support Range Based for loop") {
//	}
	for(auto i : list) {
		std::cout << i << " ";
	}
}