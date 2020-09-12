#include <iostream>

struct Node;
struct NodeIterator;

struct NodeIterator {
	NodeIterator(NodeIterator& iterator);
	NodeIterator(Node* p);

	void operator++();
	bool operator!=(const NodeIterator&);
	int operator*();

private:
	Node* itr;
};


struct Node {
	int val{};
	Node *next;

	explicit Node(int val);

	Node() = default;
	//  TODO Implement Node Destructor
};

class LinkedList : public Node {
private:
	Node *head;
	Node *tail;
	int length;
public:
	explicit LinkedList(int val);

	LinkedList();

	~LinkedList(); // TODO Implement Destructor

	void push_back(int val);

	void push_front(int val);

	void insert(int index, int val);

	void remove(int index);

	Node *traverse(int index);

	friend std::ostream &operator<<(std::ostream &os, const LinkedList &l);

	NodeIterator begin();
	NodeIterator end();

};
