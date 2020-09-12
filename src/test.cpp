#include "../include/LinkedList.hpp"
#include <catch2/catch.hpp>

TEST_CASE("LinkedList","[append]") {

LinkedList list(1);
list.append(2);
auto l = list.traverse(0);
REQUIRE(l->val == 1);
l = list.traverse(99);
REQUIRE(l->val == 2);
list.append(3);
l = list.traverse(99);
REQUIRE(l->val == 3);
list.append(4);
list.append(5);
}

TEST_CASE("LikedList","[prepend]") {

}