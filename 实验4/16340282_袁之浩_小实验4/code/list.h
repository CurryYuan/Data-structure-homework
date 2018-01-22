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

class list
{
public:
	list();
	~list();
	bool insert(char c,int p);
	bool remove(int p);
	void display();

private:
	Node* head;
	int size;
};

list::list()
{
	head = new Node('\0',NULL);
	size = 0;
}

list::~list()
{
	while (head != NULL) {
		Node* temp = head->next;
		delete head;
		head = temp;
	}

}

inline bool list::insert(char c, int p)
{
	if (p < 0 || p>size)
		return false;
	Node* temp = head;
	for (int i = 0; i < p; ++i)
		temp = temp->next;
	temp->next = new Node(c, temp->next);
	++size;
	return true;
}

inline bool list::remove(int p)
{
	if (p < 0 || p >= size)
		return false;
	Node* temp = head;
	for (int i = 0; i < p; ++i)
		temp = temp->next;
	Node* x = temp->next;
	temp->next = x->next;
	delete x;
	--size;
	return true;
}

inline void list::display()
{
	cout << "List: ";
	Node* temp = head->next;
	for (int i = 0; i < size; ++i) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}


