#pragma once
#include <iostream>
using namespace std;
const int max = 10;                //这里可以调整数组大小，暂定为10

class Quene
{
public:
	Quene();
	bool append(char c);
	bool pop();
	char top();
	void display();
private:
	int count, front, rear;
	char entry[max];
};

Quene::Quene()
{
	count = 0;
	front = 0;
	rear = max - 1;
}

inline bool Quene::append(char c)
{
	if (count >= max)
		return false;
	count++;
	rear = ((rear + 1) == max) ? 0 : (rear + 1);
	entry[rear] = c;
	return true;
}

inline bool Quene::pop()
{
	if (count <= 0)
		return false;
	count--;
	front = ((front + 1) == max) ? 0 : (front + 1);
	return true;
}

inline char Quene::top()
{
	if (count > 0)
		return entry[front];
}

inline void Quene::display()
{
	int p = front;
	cout << "Quene: ";
	for (int i = 0; i < count; ++i) {
		cout << entry[p] << " ";
		++p;
		if (p == max)
			p = 0;
	}
	cout << endl;
}



