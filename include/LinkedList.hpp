#include <iostream>


struct Node {
    int val;
    Node *next;

    explicit Node(int val);

    Node();
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

    void append(int val);

    void prepend(int val);

    void insert(int index, int val);

    void remove(int index);

    Node *traverse(int index);

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &l);
};
