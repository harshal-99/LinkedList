#include <iostream>

struct Node;
struct NodeIterator;

struct NodeIterator {
	[[maybe_unused]] NodeIterator(NodeIterator& iterator);
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
	Node();
	~Node() = default;
};

class LinkedList : public Node {
private:
	Node *head;
	Node *tail;
	size_t length{};
public:

//	explicit LinkedList(int val_);
	LinkedList();
	~LinkedList() = default;

	void push_back(int val_);
	void push_front(int val_);
	void insert(int index, int val_);
	void remove(int index_);
	Node *traverse(size_t index_);
	[[maybe_unused]] int size() const;

	friend std::ostream &operator<<(std::ostream &os, const LinkedList &l);

	NodeIterator begin() const;
	NodeIterator end() const;
	NodeIterator begin();
	NodeIterator end();
};
