#pragma once
#include <iostream>

struct node
{
	int val;
	node* left;
	node* right;
	node(int v, node* l = NULL, node* r = NULL) {
		val = v;
		left = l;
		right = r;
	}
};

class tree {
public:
	tree();
	bool insert(int v);
	void display();
	void reverse();
private:
	node* root;
	bool insertHelp(node** ro, int v);
	void displayHelp(node* ro);
	void reverseHelp(node*& ro);
};

