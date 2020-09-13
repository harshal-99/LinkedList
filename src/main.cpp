#include "../include/LinkedList.hpp"
#include <vector>

int main() {
	LinkedList a;
	std::cout << a << "\n";
	a.remove(0);
	std::cout << a << "\n";
	a.push_back(66);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	std::vector<int> v;
	std::vector<int> u {1, 2, 3, 4, 5};
	for(int i : a) {
		v.push_back(i);
	}
	std::cout << a;
}
