#pragma once
#include <iostream>
using namespace std;
struct Node {
	char val;
	Node* next;
	Node(char c, Node* p = NULL) {
		val = c;
		next = p;
	}
};

class Stack {
public:
	Stack();
	bool push(char c);
	bool pop();
	char top();
	void display();
private:
	Node* top_node;
};

Stack::Stack()
{
	top_node = NULL;
}

bool Stack::push(char c)
{
	Node* new_top = new Node(c, top_node);
	if (new_top == NULL)
		return false;
	top_node = new_top;
	return true;
}

bool Stack::pop()
{
	if (top_node == NULL)
		return false;
	Node* old = top_node;
	top_node = old->next;
	delete old;
	return true;
}

inline char Stack::top()
{
	if (top_node != NULL)
		return top_node->val;
}

inline void Stack::display()
{
	Node* p = top_node;
	cout << "Stack: ";
	while (p != NULL) {
		cout << p->val << "  ";
		p = p->next;
	}
	cout << endl;
}
