#include "../include/LinkedList.hpp"
#include <catch2/catch.hpp>
#include <vector>


TEST_CASE("LinkedList") {
	SECTION("push_back") {
		LinkedList list(1);
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
//		LinkedList a;
//		REQUIRE(a.val == 0);
//		a.push_back(1);
//		a.push_back(2);
//		a.push_back(3);
//		a.push_back(4);
//		a.push_back(5);
//		std::vector<int> v;
//		std::vector<int> u {1,2,3,4,5};
//		for(int i : a) {
//			v.push_back(i);
//		}
//		REQUIRE(v == u);
//	}
}

