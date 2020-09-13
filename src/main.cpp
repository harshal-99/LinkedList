#include "../include/LinkedList.hpp"
#include <vector>

int main() {
	LinkedList a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	std::vector<int> v;
	std::vector<int> u {1, 2, 3, 4, 5};
	for(int i : a) {
		v.push_back(i);
	}
}
