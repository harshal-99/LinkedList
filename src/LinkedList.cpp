#include <iostream>
#include "../include/LinkedList.hpp"


Node::Node(int val) : val(val), next(nullptr) {

}

Node::Node() : next(nullptr) {

}

//LinkedList::LinkedList(int val)  {
//	auto temp = new LinkedList::Node(val);
//	head = temp;
//	tail = temp;
//	length = 0;
//}

//LinkedList::~LinkedList() {
//	if(head == tail) {
//		Node::~Node();
////		delete[] this;
//	} else {
//		Node *t1 = head;
//		Node *t2 = t1->next;
//		while(t2 != nullptr) {
//			delete[] t1;
//			t1 = t2;
//			t2 = t2->next;
//		}
//	}
//}

LinkedList::LinkedList() {
	head = tail = new Node;
}


void LinkedList::push_back(int val_) {
	Node *temp = new Node(val_);
	tail->next = temp;
	tail = temp;
	length++;
}

void LinkedList::push_front(int val_) {
	Node *temp = new Node(val_);
	temp->next = head;
	head = temp;
	length++;
}


std::ostream &operator<<(std::ostream &os, const LinkedList &l) {
	Node *temp = l.head;
	while(temp != nullptr) {
		os << temp->val << " ";
		temp = temp->next;
	}
	os << "\n";
	return os;
}

void LinkedList::insert(int index, int val) {
	Node *temp = head;
	LinkedList *l = this;
	Node *t = new Node(val);
	if(index > length) {
		l->push_back(val);
	} else if(index == 0) {
		l->push_front(val);
	} else {
		index -= 1;
		while(index--) {
			temp = temp->next;
		}
		t->next = temp->next;
		temp->next = t;
	}
}

Node *LinkedList::traverse(size_t index) {
	if(index == 0) return head;
	else if(index > length) return tail;
	else {
		Node *t;
		t = head;
		while(index--) {
			t = t->next;
		}
		return t;
	}
}

void LinkedList::remove(int index) {
	Node *prev = head, *t1;
	LinkedList *l = this;
	if(index == 0) {
		head = head->next;
		delete[] prev;
	} else if(index == 1) {
		prev = head;
		if(prev->next == nullptr) return;
		t1 = prev->next;
		if(t1->next == nullptr) return;
		prev->next = t1->next;
	} else if(index > length) {
		prev = l->traverse(length - 1);
		t1 = prev->next;
		prev->next = nullptr;
		delete[] t1;
	} else {
		prev = l->traverse(index - 1);
		if(prev->next == nullptr) return;
		t1 = prev->next;
		if(t1->next == nullptr) return;
		prev->next = t1->next;
	}
	length--;
}

NodeIterator LinkedList::begin() {
	return NodeIterator(head);
}

NodeIterator LinkedList::end() {
	return NodeIterator(nullptr);
}

[[maybe_unused]] int LinkedList::size() const {
	return length;
}

NodeIterator LinkedList::begin() const {
	return head;
}

NodeIterator LinkedList::end() const {
	return NodeIterator(nullptr);
}

[[maybe_unused]] NodeIterator::NodeIterator(NodeIterator& iterator) {
	itr = iterator.itr;
}

void NodeIterator::operator++() {
	itr = itr->next;
}

NodeIterator::NodeIterator(Node *p) {
	itr = p;
}

bool NodeIterator::operator!=(const NodeIterator& iterator) {
	if(itr == iterator.itr)
		return false;
	else
		return true;
}

int NodeIterator::operator*() {
	return itr->val;
}
