#include "tree.h"

int main()
{
	tree a;
	a.insert(6);
	a.insert(3);
	a.insert(8);
	a.insert(7);
	a.insert(4);
	a.insert(2);
	a.insert(1);
	a.display();
	a.reverse();
	a.display();
	system("pause");
	return 0;
}